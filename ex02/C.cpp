#include "C.h"

C::C() {}
C::C(const C& other) { (void) other;}
const C& C::operator=(const C& other) { 
    (void)other;
    return *this;
}
C::~C() {}