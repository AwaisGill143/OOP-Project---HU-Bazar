#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include "Screen.h"
#include "TextBox.h"
#include "Button.h"
#include "UserManager.h"

class Application; // Forward declaration

class SignupScreen : public Screen
{
private:
    UserManager &userManager;
    Application *app;

    sf::Font font;
    sf::Text successMsg, errorMsg;
    sf::Text usernameLabel, passwordLabel;
    TextBox usernameField, passwordField;
    Button createAccountButton, backButton;

public:
    SignupScreen(UserManager &manager, Application *application);

    void handleInput(sf::Event &event) override;
    void update() override {}
    void render(sf::RenderWindow &window) override;

private:
    void attemptSignup();
};

#endif
