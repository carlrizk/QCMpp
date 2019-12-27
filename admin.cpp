#include "admin.h"

namespace QCMpp {

Admin::Admin(const std::string &username, const std::string &password) : User(username, password) {}

bool Admin::isAdmin() const
{
    return true;
}

}
