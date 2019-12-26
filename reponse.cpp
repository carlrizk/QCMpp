#include "reponse.h"

namespace QCMpp{
Reponse::Reponse(const std::string texte, const bool correct):texte(texte), correct(correct){}

bool Reponse::isCorrect() const {return correct;}

std::string Reponse::afficher() const{return texte;}

}
