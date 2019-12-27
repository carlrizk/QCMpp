#include "user.h"

namespace QCMpp {

User::User(const std::string &username, const std::string & password): username(username),password(password){}

User::~User(){}

std::string User::getUsername() const
{
    return username;
}

bool User::matchPassword(const std::string &pass)
{
    return pass == password;
}

}
