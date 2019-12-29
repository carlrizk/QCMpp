#ifndef MCQ_H
#define MCQ_H

#include <string>
#include<vector>
#include<memory>
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
  
    std::string getTitle();
    //to implements

    std::map<const std::string,const int> getGrades();
    //to implement

    void addQuestion(const Question & q);

    int isCorrect(const std::vector<std::vector<bool>> & u_Answers) const;
    
    void addGrade(const std::string & username,const int grade);

    std::string getTitle() const;

    std::ostream& toOstream(std::ostream& os)const;

    void toJSON(nlohmann::json & data) const;

private:
    const std::string title;
    std::vector<std::unique_ptr<const Question>> questions;
    std::map<const std::string,const int> grades;
};

std::ostream& operator<<(std::ostream& os, const MCQ& mcq);


}
#endif // MCQ_H
