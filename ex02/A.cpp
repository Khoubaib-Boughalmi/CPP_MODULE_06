#include "A.h"

A::A() {}
A::A(const A& other) { (void) other;}
const A& A::operator=(const A& other) { 
    (void)other;
    return *this;
}
A::~A() {}