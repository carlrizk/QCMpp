#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <string>
#include <unordered_map>
#include <memory>

#include "mcq.h"
#include "user.h"

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
    void onLogin(User * const user);

private:
    std::vector<std::unique_ptr<MCQ>> mcqs;
    std::unordered_map<std::string, std::unique_ptr<User>> users;

    LoginWindow loginWindow;

    User* currentUser;
    void addUser(const User & user);
    bool userExist(const User & user) const;
    User* getUser(const User & user) const;
    void login(const User & user);


};
}
#endif // APPLICATION_H
