#include "reponse.h"
#include<fstream>

namespace QCMpp{
Reponse::Reponse(const std::string texte, const bool correct):texte(texte), correct(correct){}

bool Reponse::isCorrect() const {return correct;}

void Reponse::add_tofile(std::ofstream & myfile) const{myfile << correct << " " << texte << "\n";}
}
