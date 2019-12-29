#include "application.h"

namespace QCMpp {

Application::Application(const std::string &configuration_path): currentUser(nullptr)
{
    //Load JSON

    addUser(User("test", "whvw")); //password test

    loginWindow.show();
    connect(&loginWindow, &LoginWindow::onSignInSubmit, this, &Application::onSignInSubmit);

}

Application::~Application()
{
    //Save to JSON
}

void Application::onSignInSubmit(const std::string &username, const std::string &password)
{
    User user(username, password);
    if(!userExist(user)){
        loginWindow.setMessage("Username does not exist.");
        return;
    }
    if(!getUser(user)->matchPassword(password)){
        loginWindow.setMessage("Wrong password.");
    }
    login(user);
}

void Application::onSignUpSubmit(const std::string &username, const std::string &password)
{
    User user(username, password);
    if(username.length() <= 3){
        loginWindow.setMessage("Username must be at least 3 characters long.");
        return;
    }
    if(password.length() <= 3){
        loginWindow.setMessage("Password must be at least 3 characters long.");
        return;
    }
    if(userExist(user)){
        loginWindow.setMessage("Username already in use");
        return;
    }
    addUser(user);
    login(user);
}

void Application::login(const User &user)
{
    currentUser = getUser(user);
    emit onLogin(currentUser);
}
void Application::addUser(const User &user)
{
    users[user.getUsername()] = std::unique_ptr<User>(new User(user));
}
User* Application::getUser(const User &user) const
{
    return users.at(user.getUsername()).get();
}
bool Application::userExist(const User &user) const
{
    if (users.find(user.getUsername()) == users.end() )
    {
        return false;
    }
    return true;
}

}
