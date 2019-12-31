#include "question.h"

namespace QCMpp{

Question::Question(const std::string &text) : text(text){}
Question::Question(const Question &q) : text(q.text){
    for(auto& a : q.answers)
        addAnswer(Answer(*a));
}

void Question::addAnswer(const Answer &a){
    answers.push_back(std::unique_ptr<const Answer>(new Answer(a)));
}

const std::vector<std::unique_ptr<const Answer> > &Question::getAnswers() const
{
    return answers;
}

bool Question::isCorrect(const std::vector<bool> & u_Answers) const{
    for(size_t i(0); i < answers.size(); ++i){
        if(u_Answers[i] != answers[i]->isCorrect())
            return false;
    }
    return true;
}

std::string Question::getText() const
{
    return text;
}

void Question::toJSON(nlohmann::json &data) const
{
    nlohmann::json quest;
    quest["Question"] = text;
    quest["Answers"] = {};
    for(auto& ans : answers){
        ans->toJSON(quest["Answers"]);
    }
    data.push_back(quest);
}

}
