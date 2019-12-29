#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <memory>

#include "answer.h"


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

private:
    const std::string text;
    std::vector<std::unique_ptr<const Answer>> answers;
};
}
#endif // QUESTION_H
