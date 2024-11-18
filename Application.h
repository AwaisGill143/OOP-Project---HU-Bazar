#ifndef APPLICATION_H
#define APPLICATION_H
#include<iostream>
#include "Screen.h"
#include "LoginScreen.h"
#include "SignupScreen.h"
#include "UserManager.h"
#include <SFML/Graphics.hpp>

class Application {
private:
    sf::RenderWindow window;
    Screen* currentScreen;
    UserManager userManager;

public:
    Application() : window(sf::VideoMode(800, 600), "HU Bazaar") {
        currentScreen = new LoginScreen(userManager, this);
    }

    sf::RenderWindow& getWindow() {
        return window;
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                currentScreen->handleInput(event);
            }

            currentScreen->update();
            currentScreen->render(window);
        }
    }

    void switchToSignup() {
        delete currentScreen;
        currentScreen = new SignupScreen(userManager, this);
    }

    void switchToLogin() {
        delete currentScreen;
        currentScreen = new LoginScreen(userManager, this);
    }

    ~Application() {
        delete currentScreen;
    }
};

#endif
