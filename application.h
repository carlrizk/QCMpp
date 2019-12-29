#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <string>
#include <map>
#include <memory>

#include "mcq.h"
#include "user.h"
#include "json.hpp"

#include "loginwindow.h"
#include "userwindow.h"
#include "adminwindow.h"

namespace QCMpp {

class Application : public QObject
{
    Q_OBJECT

public:
    Application(const std::string & configuration_path);

    ~Application();

public slots:
    void signInSlot(const std::string & username, const std::string & password);
    void signUpSlot(const std::string & username, const std::string & password);
    void signOutSlot();
    void requestUsersSlot();
    void requestMCQsSlot();

signals:
    void onApplicationStart(bool first_start = false);
    void onSignIn(User * const user);
    void onSignOut();
    void onSendMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs);
    void onSendUsers(const std::map<std::string, std::unique_ptr<User>> & users);

private:
    const std::string data_path;

    std::vector<std::unique_ptr<MCQ>> mcqs;
    std::map<std::string, std::unique_ptr<User>> users;

    LoginWindow loginWindow;
    UserWindow userWindow;
    AdminWindow adminWindow;

    User* currentUser;
    void addUser(const User & user);
    bool userExist(const User & user) const;
    User* getUser(const User & user) const;

    void signIn(const User & user);
    void signOut();

    void addMCQ(const MCQ & mcq);

    void doConnections();
    void undoConnections();

    void LoadData();
    void SaveData() const;

    void LoadJSON(const std::string & data);
    void SaveToJSON(nlohmann::json & data) const;

    void LoadUsers(const nlohmann::json & accounts_data);
    void SaveUsers(nlohmann::json & accounts_data) const;

    void LoadMCQs(const nlohmann::json & mcqs_data);
    void SaveMCQs(nlohmann::json & mcqs_data) const;
};
}
#endif // APPLICATION_H
