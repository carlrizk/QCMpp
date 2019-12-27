#ifndef USER_H
#define USER_H

#include <string>

namespace QCMpp{

class User
{
public:
    User(const std::string & username, bool admin = false);

    bool isAdmin() const;
    void setAdmin(bool admin);

    std::string getUsername() const;

private:
    const std::string username;
    bool admin;
};

}
#endif // USER_H
