#include <encrypter.h>
#include <iostream>
#include <string>

using namespace std;
using namespace QCMpp;

int main(int argc, char *argv[]){
    cout << endl;

    string s;

    for(int i = 32; i <= 127; ++i){
        s += char(i);
    }
    cout << s << endl << endl;

    Encrypter e;
    string c(s);

    e.encrypt(s);
    cout << s << endl << endl;
    e.decrypt(s);
    cout << s << endl << endl;
    bool equlas = c == s;
    cout << equlas;
    cout << endl;
    return 0;
}
