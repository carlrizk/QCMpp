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

    void toJSON(nlohmann::json & data) const;

private:
    const std::string text;
    const bool correct;
};

}
#endif // Answer_H
