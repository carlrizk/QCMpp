#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <memory>

#include "answer.h"
#include "json.hpp"


namespace QCMpp{
class Question
{
public:
    Question(const std::string& text);

    Question(const Question& q);

    void addAnswer(const Answer & a);

    bool isCorrect(const std::vector<bool> u_Answers) const;
    //Checks if user's choices are correct
    //Vector could contain 0s and 1s, treated as bool

    std::ostream& toOstream(std::ostream& os)const;

    void toJSON(nlohmann::json & data) const;

private:
    const std::string text;
    std::vector<std::unique_ptr<const Answer>> answers;
};

std::ostream& operator<<(std::ostream& os, const Question& quest);


}
#endif // QUESTION_H
