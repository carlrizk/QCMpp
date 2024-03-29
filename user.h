#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>

#include "json.hpp"

namespace QCMpp{

class User
{
public:
    User(const std::string & username,const std::string & password, bool admin = false);

    bool isAdmin() const;
    void setAdmin(bool admin);

    std::string getUsername() const;
    bool matchPassword(const std::string & pass)const ;

    void toJSON(nlohmann::json & data) const;

private:
    const std::string username;
    const std::string password; //Encrypted
    bool admin;
};

}
#endif // USER_H
