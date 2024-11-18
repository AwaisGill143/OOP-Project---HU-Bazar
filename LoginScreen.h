#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "Screen.h"
#include "TextBox.h"
#include "Button.h"
#include "UserManager.h"

class Application; // Forward declaration

class LoginScreen : public Screen
{
private:
    UserManager &userManager;
    Application *app;

    sf::Font font;
    sf::Text errorMsg;
    sf::Text usernameLabel, passwordLabel;
    TextBox usernameField, passwordField;
    Button loginButton, signupButton;

public:
    LoginScreen(UserManager &manager, Application *application);

    void handleInput(sf::Event &event) override;
    void update() override {}
    void render(sf::RenderWindow &window) override;

private:
    void attemptLogin();
};

#endif
