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

namespace QCMpp {

class Application : public QObject
{
    Q_OBJECT

public:
    Application(const std::string & configuration_path);

    ~Application();

public slots:
    void onSignInSubmit(const std::string & username, const std::string & password);
    void onSignUpSubmit(const std::string & username, const std::string & password);

signals:
    void onSignIn(User * const user);

private:
    const std::string data_path;
    std::vector<std::unique_ptr<MCQ>> mcqs;
    std::map<std::string, std::unique_ptr<User>> users;

    LoginWindow loginWindow;

    User* currentUser;
    void addUser(const User & user);
    bool userExist(const User & user) const;
    User* getUser(const User & user) const;
    void signIn(const User & user);

    void LoadData();
    void SaveData() const;

    void LoadJSON(const std::string & data);
    void SaveToJSON(nlohmann::json & data) const;

    void LoadUsers(const nlohmann::json & json);
    void SaveUsers(nlohmann::json & accounts_data) const;
};
}
#endif // APPLICATION_H
