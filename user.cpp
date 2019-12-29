#include "user.h"

namespace QCMpp {

User::User(const std::string &username, const std::string & password, bool admin): username(username),password(password), admin(admin){}

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

bool User::matchPassword(const std::string &pass)
{
    return pass == password;
}

void User::toJSON(nlohmann::json &data) const
{
    data[username] = { {"password", password}, {"admin", admin} };
}

}
