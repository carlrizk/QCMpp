#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "user.h"

namespace QCMpp {

class Student : public User
{
public:
    Student(const std::string & username, const std::string & password);

    bool isAdmin() const override;
};

#endif // STUDENT_H

}
