#ifndef Answer_H
#define Answer_H

#include <string>
#include "json.hpp"

namespace QCMpp{
class Answer
{
public:

    Answer(const std::string& text, const bool correct);

    bool isCorrect() const;
    std::string getText()const;

    std::ostream& toOstream(std::ostream& os)const;

    void toJSON(nlohmann::json & data) const;

private:
    const std::string text;
    const bool correct;
};

std::ostream& operator<<(std::ostream& os, const Answer& answ);


}
#endif // Answer_H
