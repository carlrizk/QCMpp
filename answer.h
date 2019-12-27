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
    std::string text;
    bool correct;
};
}
#endif // Answer_H
