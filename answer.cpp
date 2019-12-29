#include "answer.h"

namespace QCMpp{

Answer::Answer(const std::string& text, const bool correct):text(text), correct(correct){}

bool Answer::isCorrect() const {return correct;}

std::string Answer::getText() const
{
    return text;
}

std::ostream &Answer::toOstream(std::ostream &os) const
{
    return os << text;
}

void Answer::toJSON(nlohmann::json &data) const
{
    nlohmann::json ans;
    ans["Answer"] = text;
    ans["Correct"] = correct;
    data.push_back(ans);
}

std::ostream &operator<<(std::ostream &os, const Answer &answ)
{
    return answ.toOstream(os);
}

}
