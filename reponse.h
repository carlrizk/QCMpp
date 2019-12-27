#ifndef REPONSE_H
#define REPONSE_H
#include <string>
#include <fstream>

namespace QCMpp{
class Reponse
{
public:
    Reponse()=delete;

    Reponse(const std::string texte, const bool correct);

    bool isCorrect() const;

    void add_tofile(std::ofstream& myfile) const;

private:
    std::string texte;
    bool correct;
};
}
#endif // REPONSE_H
