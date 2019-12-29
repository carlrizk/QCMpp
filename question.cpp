#include "question.h"

namespace QCMpp{

Question::Question(const std::string &text) : text(text){}

Question::Question(const Question &q) : text(q.text){
    for(auto& a : q.answers)
        addAnswer(*a);
}

void Question::addAnswer(const Answer &a){
    answers.push_back(std::unique_ptr<const Answer>(new Answer(a)));
}

bool Question::isCorrect(const std::vector<bool> u_Answers) const{
    bool isCorrect = true;
    for(size_t i(0);i<answers.size() && isCorrect; ++i){
        if(u_Answers[i] != answers[i]->isCorrect())
            isCorrect = false;
    }
    return isCorrect;
}

}
