#include "student.h"

namespace QCMpp {

Student::Student(const std::string &username, const std::string &password) : User(username, password){}

bool Student::isAdmin() const
{
    return false;
}


}
