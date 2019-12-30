#ifndef MCQ_H
#define MCQ_H

#include <string>
#include <vector>
#include <memory>
#include <map>

#include "question.h"
#include "user.h"
#include "json.hpp"

namespace QCMpp{
class MCQ
{
public:
    MCQ(const std::string & title);
    MCQ(const MCQ & mcq);

    void addQuestion(const Question & q);
    void addGrade(const std::string & username,const int grade);

    int correct(const std::vector<std::vector<bool>> & u_Answers) const;
    
    std::string getTitle() const;
    const Question *getQuestion(int id) const;
    int getGrade(const std::string & username) const;
    bool hasGrade(const std::string & username) const;
    const std::map<const std::string, const int> * getGrades() const ;

    void toJSON(nlohmann::json & data) const;

private:
    const std::string title;
    std::vector<std::unique_ptr<const Question>> questions;
    std::map<const std::string, const int> grades;
};

}
#endif // MCQ_H
