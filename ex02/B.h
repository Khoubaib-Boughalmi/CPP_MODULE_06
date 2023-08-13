#ifndef B_H
#define B_H

#include "Base.h"

class B: public Base
{
    private:
    public:
        B();
        B(const B& other);
        const B& operator=(const B& other);
        ~B();
};

#endif