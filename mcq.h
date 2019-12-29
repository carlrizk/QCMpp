#ifndef MCQ_H
#define MCQ_H
#include <string>
#include<vector>
#include<memory>
#include <map>
#include "question.h"
#include "user.h"

namespace QCMpp{
class MCQ
{
public:
    MCQ(const std::string & title);

    void addQuestion(const Question & q);

    int isCorrect(const std::vector<std::vector<bool>> & u_Answers) const;
    
    void addGrade(const User & u,const int grade);

private:
    const std::string title;
    std::vector<std::unique_ptr<const Question>> questions;
    std::map<const std::string,const int> grades;
};
}
#endif // MCQ_H
