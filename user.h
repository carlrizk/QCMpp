#ifndef USER_H
#define USER_H

#include <string>

namespace QCMpp{

class User
{
public:
    User(const std::string & username,const std::string & password);
//    User (const User &user) = delete;

    virtual bool isAdmin() const = 0;
    virtual ~User();

    std::string getUsername() const;
    bool matchPassword(const std::string & pass);

private:
    const std::string username;
    const std::string password; //Encrypted
};

}
#endif // USER_H
