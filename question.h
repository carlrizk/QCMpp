#ifndef QUESTION_H
#define QUESTION_H
#include "reponse.h"
#include <string>
#include <vector>


namespace QCMpp{
class Question
{
public:
    Question() = delete;
    Question(const Question& q) = delete;

    Question(const std::string& texte);
    //arbitrary number of choices

    void add_choice(const Reponse & r);

    bool correct(std::vector<bool> u_reponses) const;
    //Checks if user's choices are correct
    //Vector could contain 0s and 1s, treated as bool

    void add_tofile(const std::string filename)const;
    // not functional yet, and thinking of implementing it in QCM class instead

private:
    std::string texte;
    std::vector<Reponse> choix;
};
}
#endif // QUESTION_H
