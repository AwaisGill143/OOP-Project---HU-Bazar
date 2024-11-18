#include "LoginScreen.h"
#include "Application.h" // Full definition of Application is needed here

LoginScreen::LoginScreen(UserManager &manager, Application *application)
    : userManager(manager), app(application),
      usernameField(250, 100, 200, 30, font),
      passwordField(250, 200, 200, 30, font, true),
      loginButton(150, 300, 100, 40, "Login", font),
      signupButton(300, 300, 150, 40, "Signup", font)
{

    font.loadFromFile("arial.ttf");

    // Labels for username and password fields
    usernameLabel.setFont(font);
    usernameLabel.setString("Username:");
    usernameLabel.setCharacterSize(20);
    usernameLabel.setFillColor(sf::Color::White);
    usernameLabel.setPosition(150, 105);

    passwordLabel.setFont(font);
    passwordLabel.setString("Password:");
    passwordLabel.setCharacterSize(20);
    passwordLabel.setFillColor(sf::Color::White);
    passwordLabel.setPosition(150, 205);

    errorMsg.setFont(font);
    errorMsg.setPosition(150, 350);
    errorMsg.setCharacterSize(20);

    loginButton.setOnClick([this]()
                           { attemptLogin(); });
    signupButton.setOnClick([this]()
                            { app->switchToSignup(); });
}

void LoginScreen::handleInput(sf::Event &event)
{
    usernameField.handleInput(event);
    passwordField.handleInput(event);

    loginButton.handleEvent(event, app->getWindow());
    signupButton.handleEvent(event, app->getWindow());
}

void LoginScreen::render(sf::RenderWindow &window)
{
    window.clear();
    usernameField.render(window);
    passwordField.render(window);
    loginButton.render(window);
    signupButton.render(window);
    window.draw(errorMsg);
    window.display();
}

void LoginScreen::attemptLogin()
{
    if (userManager.login(usernameField.getText(), passwordField.getText()))
    {
        errorMsg.setString("Login Successful!");
        errorMsg.setFillColor(sf::Color::Green);
    }
    else
    {
        errorMsg.setString("Invalid credentials!");
        errorMsg.setFillColor(sf::Color::Red);
    }
}
