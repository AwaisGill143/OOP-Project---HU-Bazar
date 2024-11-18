#include "SignupScreen.h"
#include "Application.h" // Full definition of Application is needed here

SignupScreen::SignupScreen(UserManager &manager, Application *application)
    : userManager(manager), app(application),
      usernameField(250, 100, 200, 30, font),
      passwordField(250, 200, 200, 30, font, true),
      createAccountButton(200, 300, 150, 40, "Create", font),
      backButton(400, 300, 100, 40, "Back", font)
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

    successMsg.setFont(font);
    successMsg.setPosition(150, 400);
    successMsg.setCharacterSize(20);

    errorMsg.setFont(font);
    errorMsg.setPosition(150, 450);
    errorMsg.setCharacterSize(20);

    createAccountButton.setOnClick([this]()
                                   { attemptSignup(); });
    backButton.setOnClick([this]()
                          { app->switchToLogin(); });
}

void SignupScreen::handleInput(sf::Event &event)
{
    usernameField.handleInput(event);
    passwordField.handleInput(event);

    createAccountButton.handleEvent(event, app->getWindow());
    backButton.handleEvent(event, app->getWindow());
}

void SignupScreen::render(sf::RenderWindow &window)
{
    window.clear();
    usernameField.render(window);
    passwordField.render(window);
    createAccountButton.render(window);
    backButton.render(window);
    window.draw(successMsg);
    window.draw(errorMsg);
    window.display();
}

void SignupScreen::attemptSignup()
{
    if (usernameField.getText().empty() || passwordField.getText().empty())
    {
        errorMsg.setString("Fields cannot be empty!");
        errorMsg.setFillColor(sf::Color::Red);
        return;
    }

    if (userManager.signup(usernameField.getText(), passwordField.getText()))
    {
        successMsg.setString("Account created successfully!");
        successMsg.setFillColor(sf::Color::Green);
        app->switchToLogin();
    }
    else
    {
        errorMsg.setString("Username already exists!");
        errorMsg.setFillColor(sf::Color::Red);
    }
}
