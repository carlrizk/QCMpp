#include "question.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

namespace QCMpp{
Question::Question(const string &texte) : texte(texte){}

void Question::add_choice(const Reponse& r){choix.push_back(r);}

bool Question::correct(std::vector<bool> u_reponses) const{
    bool isCorrect = true;
    for(size_t i(0);i<choix.size() && isCorrect; ++i){
        if(u_reponses[i] != choix[i].isCorrect())
            isCorrect = false;
    }
    return isCorrect;
}

void QCMpp::Question::Question::add_tofile(const string filename) const
{
    std::ofstream myfile;
    myfile.open(filename,ios::ate);
    myfile << texte << "\n";
    for(auto c : choix){
        myfile << c.isCorrect() << " " << c.afficher() << "\n";
    }
    myfile << "\n";
    myfile.close();
}



}
