#include "user.h"

namespace QCMpp {

User::User(const std::string &username, bool admin): username(username), admin(admin){}

bool User::isAdmin() const
{
    return admin;
}

void User::setAdmin(bool admin)
{
    this->admin = admin;
}

std::string User::getUsername() const
{
    return username;
}

}
