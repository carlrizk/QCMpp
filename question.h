#ifndef QUESTION_H
#define QUESTION_H
#include "answer.h"
#include <vector>
#include <memory>

namespace QCMpp{
class Question
{
public:
    Question(const std::string& text);

    Question(const Question& q);

    void add_answer(const Answer & a);

    bool correct(const std::vector<bool> u_Answers) const;
    //Checks if user's choices are correct
    //Vector could contain 0s and 1s, treated as bool

private:
    const std::string text;
    std::vector<std::unique_ptr<const Answer>> answers;
};
}
#endif // QUESTION_H
