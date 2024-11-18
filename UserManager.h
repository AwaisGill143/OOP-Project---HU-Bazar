#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>

class UserManager {
private:
    std::unordered_map<std::string, std::size_t> users;
    const std::string file = "users.txt";

public:
    UserManager() {
        loadUsers();
    }

    void loadUsers() {
        std::ifstream infile(file);
        std::string line;
        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            std::string username, hash;
            if (std::getline(iss, username, ':') && std::getline(iss, hash)) {
                users[username] = std::stoull(hash);
            }
        }
    }

    bool login(const std::string& username, const std::string& password) const {
        auto it = users.find(username);
        return it != users.end() && it->second == std::hash<std::string>{}(password);
    }

    bool signup(const std::string& username, const std::string& password) {
        if (users.find(username) != users.end()) return false;
        std::size_t hash = std::hash<std::string>{}(password);
        users[username] = hash;
        std::ofstream outfile(file, std::ios::app);
        outfile << username << ":" << hash << "\n";
        return true;
    }
};

#endif
