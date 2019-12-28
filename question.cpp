#include "question.h"

using namespace std;

namespace QCMpp{

Question::Question(const Question &q) : text(q.text){
    for(auto& a : q.answers)
        add_answer(*a);
}

Question::Question(const string &text) : text(text){}

void Question::add_answer(const Answer& a){answers.push_back(unique_ptr<const Answer>(new Answer(a)));}

bool Question::correct(const std::vector<bool> u_Answers) const{
    bool isCorrect = true;
    for(size_t i(0);i<answers.size() && isCorrect; ++i){
        if(u_Answers[i] != answers[i]->isCorrect())
            isCorrect = false;
    }
    return isCorrect;
}

}
