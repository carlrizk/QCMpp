#include "mcq.h"

namespace QCMpp {

MCQ::MCQ(const std::string &title) :
    title(title){}

MCQ::MCQ(const MCQ &mcq):
    title(mcq.title), grades(mcq.grades)
{
    for(auto& question: mcq.questions){
        addQuestion(Question(*question));
    }
}

void MCQ::addQuestion(const QCMpp::Question &q){
    questions.push_back(std::unique_ptr<Question>(new Question(q)));
}
void MCQ::addGrade(const std::string & username, const int grade){
    grades.insert({username, grade});
}

int MCQ::correct(const std::vector<std::vector<bool> > &u_Answers) const{
    int right_a(0);
    size_t n_questions = questions.size();
    for(size_t i(0); i< n_questions; ++i){
        if(questions[i]->isCorrect(u_Answers[i]))
            ++right_a;
    }
    return  right_a * 100/n_questions;
}

std::string MCQ::getTitle() const{
    return title;
}

int MCQ::getGrade(const std::string & username) const
{
    return grades.at(username);
}
bool MCQ::hasGrade(const std::string &username) const
{
    if (grades.find(username) == grades.end() )
    {
        return false;
    }
    return true;
}
const std::map<const std::string, const int> & MCQ::getGrades() const{
    return grades;
}

const std::vector<std::unique_ptr<const Question> > & MCQ::getQuestions() const
{
    return questions;
}

void MCQ::toJSON(nlohmann::json &data) const
{
    nlohmann::json mcq;
    mcq["Title"] = title;
    for(auto& quest : questions){
        quest->toJSON(mcq["Questions"]);
    }
    mcq["Passed Students"] = {};
    for(auto it = grades.begin(); it != grades.end(); ++it){
        mcq["Passed Students"][it->first] = it->second;
    }
    data.push_back(mcq);
}

}
