#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <string>

using namespace std;

namespace QCMpp {

class Encrypter
{
public:
    Encrypter(int shift = 3);

    void encrypt(string & source);
    void decrypt(string & source);
private:
    int shift;

    void ceaser(string & source, int shift);
};

}
#endif // ENCRYPTER_H
