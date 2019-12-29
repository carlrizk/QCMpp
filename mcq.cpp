#include "mcq.h"

namespace QCMpp {

MCQ::MCQ(const std::string &title) : title(title){}

void MCQ::addQuestion(const QCMpp::Question &q){
    questions.push_back(std::unique_ptr<Question>(new Question(q)));
}

int MCQ::isCorrect(const std::vector<std::vector<bool> > &u_Answers) const{
    int right_a(0);
    size_t n_questions = questions.size();
    for(size_t i(0); i< n_questions; ++i){
        if(questions[i]->isCorrect(u_Answers[i]) == true)
            ++right_a;
    }
    return right_a/n_questions;
}

void MCQ::addGrade(const QCMpp::User & u,const int grade){
    grades.insert({u.getUsername(), grade});
}

}
