#include "answer.h"
#include<fstream>

namespace QCMpp{
Answer::Answer(const std::string& texte, const bool correct):texte(texte), correct(correct){}

bool Answer::isCorrect() const {return correct;}
}
