#ifndef Answer_H
#define Answer_H
#include <string>

namespace QCMpp{
class Answer
{
public:

    Answer(const std::string& text, const bool correct);

    bool isCorrect() const;

private:
    const std::string text;
    const bool correct;
};
}
#endif // Answer_H
