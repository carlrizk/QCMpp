#include "mcq.h"
using namespace std;

QCMpp::MCQ::MCQ(const std::string &title) : title(title){}

void QCMpp::MCQ::add_question(const QCMpp::Question &q){questions.push_back(unique_ptr<Question>(new Question(q)));
}

int QCMpp::MCQ::correct(const std::vector<const std::vector<bool> > &u_Answers) const{
    int right_a(0);
    size_t n_questions = questions.size();
    for(size_t i(0); i< n_questions; ++i){
        if(questions[i]->correct(u_Answers[i]) == true)
            ++right_a;
    }
    return right_a/n_questions;
}

void QCMpp::MCQ::add_grade(const QCMpp::User & u, int grade){grades.insert({u.getUsername(), grade});}
