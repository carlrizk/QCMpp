#include "question.h"

using namespace std;

namespace QCMpp{
Question::Question(const string &texte) : texte(texte){}

void Question::add_choice(const Reponse& r){choix.push_back(r);}

bool Question::correct(const std::vector<bool> u_reponses) const{
    bool isCorrect = true;
    for(size_t i(0);i<choix.size() && isCorrect; ++i){
        if(u_reponses[i] != choix[i].isCorrect())
            isCorrect = false;
    }
    return isCorrect;
}

ofstream &Question::add_tofile(ofstream & myfile)const{
    myfile << texte << "\n";
    for(auto c : choix)
        c.add_tofile(myfile);
    myfile << "\n";
    return myfile;
}


}
