#include "B.h"

B::B() {}
B::B(const B& other) { (void) other;}
const B& B::operator=(const B& other) { 
    (void)other;
    return *this;
}
B::~B() {}