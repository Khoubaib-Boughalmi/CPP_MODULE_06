#ifndef C_H
#define C_H

#include "Base.h"

class C: public Base
{
    private:
    public:
        C();
        C(const C& other);
        const C& operator=(const C& other);
        ~C();
};

#endif