#ifndef MCQ_H
#define MCQ_H
#include <string>
#include<vector>
#include<memory>
#include <unordered_map>
#include "question.h"
#include "user.h"

namespace QCMpp{
class MCQ
{
public:
    MCQ(const std::string & title);

    void add_question(const Question & q);

    int correct(const std::vector<std::vector<bool>> & u_Answers) const;
    
    void add_grade(const User & u, int grade);

private:
    const std::string title;
    std::vector<std::unique_ptr<const Question>> questions;
    std::unordered_map<std::string,int> grades;
};
}
#endif // MCQ_H
