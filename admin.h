#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "user.h"

namespace QCMpp{

class Admin : public User
{
public:
    Admin(const std::string & username, const std::string & password);

    bool isAdmin() const override;
};

}

#endif // ADMIN_H
