#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <memory>

#include "answer.h"
#include "json.hpp"


namespace QCMpp{
class Question
{
public:
    Question(const std::string& text);
    Question(const Question& q);

    void addAnswer(const Answer & a);

    const std::vector<std::unique_ptr<const Answer>> & getAnswers()const;

    bool isCorrect(const std::vector<bool> & u_Answers) const;
    std::string getText() const;

    void toJSON(nlohmann::json & data) const;

private:
    const std::string text;
    std::vector<std::unique_ptr<const Answer>> answers;
};

}
#endif // QUESTION_H
