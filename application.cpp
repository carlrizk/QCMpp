#include "application.h"

namespace QCMpp {

Application::Application(const std::string &configuration_path)
{
    //Load JSON
    //connect(loginWindow, )

    loginWindow.show();
    connect(&loginWindow, &LoginWindow::onSignInSubmit, this, &Application::onSignInSubmit);

}

Application::~Application()
{
    //Save to JSON
}

void Application::onSignInSubmit(const std::string &username, const std::string &password)
{
    User u(username, password);
    if(userExist(u)){
        // check password
    }else {
        loginWindow.setMessage("Username does not exist");
    }
}

void Application::onSignUpSubmit(const std::string &username, const std::string &password)
{
    User u(username, password);
    if(userExist(u)){
        loginWindow.setMessage("Username already in use");
    }else {
        addUser(u);
        //Continue
    }
}

void Application::addUser(const User &user)
{
    users[user.getUsername()] = std::unique_ptr<User>(new User(user));
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
