#ifndef Answer_H
#define Answer_H
#include <string>
#include <fstream>

namespace QCMpp{
class Answer
{
public:

    Answer(const std::string& texte, const bool correct);

    bool isCorrect() const;

private:
    std::string texte;
    bool correct;
};
}
#endif // Answer_H
