#include "question.h"

using namespace std;

namespace QCMpp{

Question::Question(const string &text) : text(text){}

void Question::add_choice(const Answer& a){choices.push_back(unique_ptr<const Answer>(new Answer(a)));}

bool Question::correct(const std::vector<bool> u_Answers) const{
    bool isCorrect = true;
    for(size_t i(0);i<choices.size() && isCorrect; ++i){
        if(u_Answers[i] != choices[i]->isCorrect())
            isCorrect = false;
    }
    return isCorrect;
}

}
