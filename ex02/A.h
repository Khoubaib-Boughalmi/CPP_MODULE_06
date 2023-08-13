#ifndef A_H
#define A_H

#include "Base.h"

class A: public Base
{
    private:
    public:
        A();
        A(const A& other);
        const A& operator=(const A& other);
        ~A();
};

#endif