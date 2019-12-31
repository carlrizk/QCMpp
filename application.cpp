#include "application.h"

#include <fstream>
#include "json.hpp"
#include "encrypter.h"

#include <mcq.h>

namespace QCMpp {

Application::Application(const std::string &data_path): data_path(data_path), currentUser(nullptr)
{
    //LoadData();

    connect(this, &Application::onApplicationStart, &loginWindow, &LoginWindow::showWindow);

    connect(&loginWindow, &LoginWindow::onSignInSubmit, this, &Application::signInSlot);
    connect(&loginWindow, &LoginWindow::onSignUpSubmit, this, &Application::signUpSlot);

    connect(this, &Application::onSignIn, &loginWindow, &LoginWindow::hideWindow);
    connect(this, &Application::onSignOut, &loginWindow, &LoginWindow::show);

    MCQ mcq("MCQ#1");                               //
    Question question("Question#1");
    question.addAnswer(Answer("Answer#1", true));
    question.addAnswer(Answer("Answer#2", false));
    question.addAnswer(Answer("Answer#3", false));
    question.addAnswer(Answer("Answer#4", false));
    mcq.addQuestion(question);

    Question question2("Question#2");
    question2.addAnswer(Answer("Answer#1", true));
    question2.addAnswer(Answer("Answer#2", false));
    question2.addAnswer(Answer("Answer#3", false));
    question2.addAnswer(Answer("Answer#4", false));
    mcq.addQuestion(question2);

    Question question3("Question#3");
    question3.addAnswer(Answer("Answer#1", true));
    question3.addAnswer(Answer("Answer#2", false));
    question3.addAnswer(Answer("Answer#3", false));
    question3.addAnswer(Answer("Answer#4", false));
    mcq.addQuestion(question3);

    addMCQ(mcq);

    addUser(User("adm", "dgp", true));
    addUser(User("stu","vwx"));                     //

    emit onApplicationStart(users.size() == 0);
}

Application::~Application()
{
    //SaveData();
}

void Application::doConnections()
{
    if(currentUser->isAdmin()){
        connect(&adminWindow, &AdminWindow::onSignOutSubmit, this, &Application::signOutSlot);

        connect(this, &Application::onSignIn, &adminWindow, &AdminWindow::showWindow);
        connect(this, &Application::onSignOut, &adminWindow, &AdminWindow::hideWindow);

        connect(&adminWindow, &AdminWindow::onRequestMCQs, this, &Application::requestMCQsSlot);
        connect(&adminWindow, &AdminWindow::onRequestUsers, this, &Application::requestUsersSlot);
        connect(&adminWindow, &AdminWindow::onRequestChangeRank, this, &Application::requestRankChangeSlot);

        connect(this, &Application::onSendMCQs, &adminWindow, &AdminWindow::updateMCQs);
        connect(this, &Application::onSendUsers, &adminWindow, &AdminWindow::updateUsers);


    }else{
        connect(&userWindow, &UserWindow::onSignOutSubmit, this, &Application::signOutSlot);

        connect(this, &Application::onSignIn, &userWindow, &UserWindow::showWindow);
        connect(this, &Application::onSignOut, &userWindow, &UserWindow::hideWindow);

        connect(&userWindow, &UserWindow::onRequestMCQs, this, &Application::requestMCQsSlot);

        connect(this, &Application::onSendMCQs, &userWindow, &UserWindow::updateMCQs);

        connect(&userWindow, &UserWindow::onTakeMCQSubmit, this, &Application::takeMCQSlot);
        connect(this, &Application::onTakeMCQ, &mcqWidget, &MCQWindow::showWindow);
        connect(this, &Application::onTakeMCQ, &userWindow, &UserWindow::hideWindow);

        connect(&mcqWidget, &MCQWindow::onCancelSubmit, this, &Application::cancelMCQSlot);
        connect(this, &Application::onCancelMCQ, &mcqWidget, &MCQWindow::hideWindow);
        connect(this, &Application::onCancelMCQ, &userWindow, &UserWindow::showWindow);

        connect(&mcqWidget, &MCQWindow::onFinishMCQSubmit, this, &Application::finishMCQSlot);
        connect(this, &Application::onFinishMCQ, &mcqWidget, &MCQWindow::hideWindow);
        connect(this, &Application::onFinishMCQ, &userWindow, &UserWindow::showWindow);
    }
}

void Application::undoConnections()
{
    if(currentUser->isAdmin()){
        disconnect(&adminWindow, &AdminWindow::onSignOutSubmit, this, &Application::signOutSlot);

        disconnect(this, &Application::onSignIn, &adminWindow, &AdminWindow::showWindow);
        disconnect(this, &Application::onSignOut, &adminWindow, &AdminWindow::hideWindow);

        disconnect(&adminWindow, &AdminWindow::onRequestMCQs, this, &Application::requestMCQsSlot);
        disconnect(&adminWindow, &AdminWindow::onRequestUsers, this, &Application::requestUsersSlot);
        disconnect(&adminWindow, &AdminWindow::onRequestChangeRank, this, &Application::requestRankChangeSlot);

        disconnect(this, &Application::onSendMCQs, &adminWindow, &AdminWindow::updateMCQs);
        disconnect(this, &Application::onSendUsers, &adminWindow, &AdminWindow::updateUsers);
    }else{
        disconnect(&userWindow, &UserWindow::onSignOutSubmit, this, &Application::signOutSlot);

        disconnect(this, &Application::onSignIn, &userWindow, &UserWindow::showWindow);
        disconnect(this, &Application::onSignOut, &userWindow, &UserWindow::hideWindow);

        disconnect(&userWindow, &UserWindow::onRequestMCQs, this, &Application::requestMCQsSlot);

        disconnect(this, &Application::onSendMCQs, &userWindow, &UserWindow::updateMCQs);

        disconnect(&userWindow, &UserWindow::onTakeMCQSubmit, this, &Application::takeMCQSlot);
        disconnect(this, &Application::onTakeMCQ, &mcqWidget, &MCQWindow::showWindow);
        disconnect(this, &Application::onTakeMCQ, &userWindow, &UserWindow::hideWindow);

        disconnect(&mcqWidget, &MCQWindow::onCancelSubmit, this, &Application::cancelMCQSlot);
        disconnect(this, &Application::onCancelMCQ, &mcqWidget, &MCQWindow::hideWindow);
        disconnect(this, &Application::onCancelMCQ, &userWindow, &UserWindow::showWindow);

        disconnect(&mcqWidget, &MCQWindow::onFinishMCQSubmit, this, &Application::finishMCQSlot);
        disconnect(this, &Application::onFinishMCQ, &mcqWidget, &MCQWindow::hideWindow);
        disconnect(this, &Application::onFinishMCQ, &userWindow, &UserWindow::showWindow);
    }
}

void Application::signInSlot(const std::string &username, const std::string &password)
{
    User user(username, password);
    if(!userExist(user)){
        loginWindow.setMessage("Username does not exist.");
        return;
    }
    if(!getUser(user).matchPassword(password)){
        loginWindow.setMessage("Wrong password.");
        return;
    }
    signIn(user);
}
void Application::signUpSlot(const std::string &username, const std::string &password)
{
    User user(username, password, users.size() == 0);
    if(username.length() < 3){
        loginWindow.setMessage("Username must be at least 3 characters long.");
        return;
    }
    if(password.length() < 3){
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
    emit onSendUsers(users);
}
void Application::requestMCQsSlot()
{
    emit onSendMCQs(mcqs);
}

void Application::requestRankChangeSlot(const string &username, bool isAdmin)
{
    users[username]->setAdmin(!isAdmin);
    emit onSendUsers(users);
}

void Application::cancelMCQSlot()
{
    emit onCancelMCQ(*currentUser);
}

void Application::takeMCQSlot(int mcq_id)
{
    MCQ * mcq = mcqs[mcq_id].get();
    emit  onTakeMCQ(*currentUser, *mcq);
}

void Application::finishMCQSlot()
{
    emit onFinishMCQ(*currentUser);
}

void Application::signIn(const User &user)
{
    currentUser = &getUser(user);
    doConnections();
    emit onSignIn(*currentUser);
}
void Application::signOut()
{
    emit onSignOut();
    undoConnections();
    currentUser = nullptr;
}

void Application::addMCQ(const MCQ &mcq)
{
    mcqs.push_back(std::unique_ptr<MCQ>(new MCQ(mcq)));
}

void Application::addUser(const User &user)
{
    users[user.getUsername()] = std::unique_ptr<User>(new User(user));
}
const User& Application::getUser(const User &user) const
{
    return *users.at(user.getUsername()).get();
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

    json mcqs_data = json_data["MCQs"];
    LoadMCQs(mcqs_data);
}
void Application::SaveToJSON(nlohmann::json & data) const
{
    data["Accounts"]= {};
    SaveUsers(data["Accounts"]);
    data["MCQs"] = {};
    SaveMCQs(data["MCQs"]);
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

void Application::LoadMCQs(const nlohmann::json &mcqs_data)
{
    for (auto& mcq_data : mcqs_data) {
        MCQ mcq(mcq_data["Title"]);
        nlohmann::json passed_students_data = mcq_data["Passed Students"];
        for (auto it = passed_students_data.begin(); it != passed_students_data.end(); ++it) {
            mcq.addGrade(it.key(), it.value());
        }
        nlohmann::json questions_data = mcq_data["Questions"];
        for(auto& quest_data : questions_data){
            Question quest(quest_data["Question"]);
            nlohmann::json answers_data = quest_data["Answers"];
            for(auto& ans_data : answers_data){
                Answer ans(ans_data["Answer"], ans_data["Correct"]);
                quest.addAnswer(ans);
            }
            mcq.addQuestion(quest);
        }
        addMCQ(mcq);
    }
}

void Application::SaveMCQs(nlohmann::json &mcqs_data) const
{
    for (auto &mcq : mcqs) {
        mcq->toJSON(mcqs_data);
    }
}

}
