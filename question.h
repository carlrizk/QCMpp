#ifndef QUESTION_H
#define QUESTION_H
#include "answer.h"
#include <vector>

namespace QCMpp{
class Question
{
public:
    Question(const Question& q) = delete;

    Question(const std::string& texte);
    //arbitrary number of choices

    void add_choice(const Answer & r);

    bool correct(const std::vector<bool> u_Answers) const;
    //Checks if user's choices are correct
    //Vector could contain 0s and 1s, treated as bool

private:
    std::string texte;
    std::vector<Answer> choix;
};
}
#endif // QUESTION_H
