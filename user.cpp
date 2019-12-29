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

std::ostream &User::toOstream(std::ostream &os) const
{
    os << "Username: " << username << " , admin: " << admin;
    return os;
}

void User::toJSON(nlohmann::json &data) const
{
    data[username] = { {"password", password}, {"admin", admin} };
}

std::ostream &operator<<(std::ostream &os, const User &user)
{
        return user.toOstream(os);
}

}
