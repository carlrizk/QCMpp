#include "application.h"

#include <fstream>
#include "json.hpp"
#include "encrypter.h"

namespace QCMpp {

Application::Application(const std::string &data_path): data_path(data_path), currentUser(nullptr)
{
    LoadData();

    connect(this, &Application::onApplicationStart, &loginWindow, &LoginWindow::showWindow);

    connect(&loginWindow, &LoginWindow::onSignInSubmit, this, &Application::signInSlot);
    connect(&loginWindow, &LoginWindow::onSignUpSubmit, this, &Application::signUpSlot);

    connect(&userWindow, &UserWindow::onSignOutSubmit, this, &Application::signOutSlot);

    connect(this, &Application::onSignIn, &loginWindow, &LoginWindow::hideWindow);
    connect(this, &Application::onSignIn, &userWindow, &UserWindow::showWindow);

    connect(this, &Application::onSignOut, &userWindow, &UserWindow::hideWindow);
    connect(this, &Application::onSignOut, &loginWindow, &LoginWindow::show);

    emit onApplicationStart(users.size() == 0);
}

Application::~Application()
{
    SaveData();
}

void Application::signInSlot(const std::string &username, const std::string &password)
{
    User user(username, password);
    if(!userExist(user)){
        loginWindow.setMessage("Username does not exist.");
        return;
    }
    if(!getUser(user)->matchPassword(password)){
        loginWindow.setMessage("Wrong password.");
        return;
    }
    signIn(user);
}
void Application::signUpSlot(const std::string &username, const std::string &password)
{
    User user(username, password, users.size() == 0);
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
    signIn(user);
}
void Application::signOutSlot()
{
    signOut();
}

void Application::requestUsersSlot()
{
    emit onRequestUsers(users);
}
void Application::requestMCQsSlot()
{
    emit onRequestMCQs(mcqs);
}

void Application::signIn(const User &user)
{
    currentUser = getUser(user);
    emit onSignIn(currentUser);
}
void Application::signOut()
{
    currentUser = nullptr;
    emit onSignOut();
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

void Application::LoadData()
{
    std::ifstream file(data_path);
    std::string data( (std::istreambuf_iterator<char>(file) ),
                      (std::istreambuf_iterator<char>()    ) );
    file.close();
    if(data.empty()) return;
    Encrypter e;
    e.decrypt(data);
    LoadJSON(data);
}
void Application::SaveData() const
{
    nlohmann::json data;
    SaveToJSON(data);
    std::string data_string = data.dump();
    Encrypter e;
    e.encrypt(data_string);
    std::ofstream file(data_path);
    file << data_string;
    file.close();
}

void Application::LoadJSON(const std::string & data)
{
    using namespace nlohmann;
    json json_data = json::parse(data);

    json accounts_data = json_data["Accounts"];
    LoadUsers(accounts_data);

    //LOAD MCQs
}
void Application::SaveToJSON(nlohmann::json & data) const
{
    data["Accounts"]= {};
    SaveUsers(data["Accounts"]);
    //Save MCQs
}

void Application::LoadUsers(const nlohmann::json & accounts_data)
{
    for (auto it = accounts_data.begin(); it != accounts_data.end(); ++it) {
        addUser(User(it.key(), it.value()["password"], it.value()["admin"]));
    }
}
void Application::SaveUsers(nlohmann::json & accounts_data) const
{
    for (auto &user : users) {
        user.second->toJSON(accounts_data);
    }
}

}
