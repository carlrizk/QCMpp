#ifndef QUESTION_H
#define QUESTION_H
#include "answer.h"
#include <vector>
#include <memory>

namespace QCMpp{
class Question
{
public:
    Question(const Question& q) = delete;

    Question(const std::string& text);
    //arbitrary number of choices

    void add_choice(const Answer & a);

    bool correct(const std::vector<bool> u_Answers) const;
    //Checks if user's choices are correct
    //Vector could contain 0s and 1s, treated as bool

private:
    const std::string text;
    std::vector<std::unique_ptr<const Answer>> choices;
};
}
#endif // QUESTION_H
