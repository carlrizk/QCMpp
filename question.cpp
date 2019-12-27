#include "question.h"

using namespace std;

namespace QCMpp{

Question::Question(const string &texte) : texte(texte){}

void Question::add_choice(const Answer& r){choix.push_back(r);}

bool Question::correct(const std::vector<bool> u_Answers) const{
    bool isCorrect = true;
    for(size_t i(0);i<choix.size() && isCorrect; ++i){
        if(u_Answers[i] != choix[i].isCorrect())
            isCorrect = false;
    }
    return isCorrect;
}

}
