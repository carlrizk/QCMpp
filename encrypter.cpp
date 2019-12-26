#include "encrypter.h"

namespace QCMpp {

Encrypter::Encrypter(int shift) : shift(shift){}

void Encrypter::encrypt(string &source)
{
    ceaser(source, shift);
}

void Encrypter::decrypt(string &source)
{
    ceaser(source, -shift);
}

void Encrypter::ceaser(string &source, int shift)
{
    for(char& c : source){
        c -= 32;            //Printable characters start at 32 and end at 127
        c += shift;
        if(c < 0) c += 96;  //Loopback if negative
        c %= 96;            //There are 96 printable characters
        c += 32;
    }
}

}
