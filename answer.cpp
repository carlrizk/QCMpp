#include "answer.h"

namespace QCMpp{

Answer::Answer(const std::string& text, const bool correct):text(text), correct(correct){}

bool Answer::isCorrect() const {return correct;}

std::string Answer::getText() const
{
    return text;
}

}
