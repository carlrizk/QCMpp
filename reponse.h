#ifndef REPONSE_H
#define REPONSE_H
#include <string>

namespace QCMpp{
class Reponse
{
public:
    Reponse()=delete;

    Reponse(const std::string texte, const bool correct);

    bool isCorrect() const;

    std::string afficher() const;

private:
    std::string texte;
    const bool correct;
};
}
#endif // REPONSE_H
