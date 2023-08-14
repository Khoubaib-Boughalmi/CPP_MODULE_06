#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base * generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int randVal = (std::rand() % 10);
    if(randVal >= 0 && randVal <= 3 )
        return new A();
    if(randVal >= 4 && randVal <= 6 )
        return new B();
    if(randVal >= 7 && randVal <= 9 )
        return new C();
    return (0);
}

void identify(Base* p)
{
    A *classA = dynamic_cast<A*>(p);
    if(classA)
    {
        std::cout << "A" << std::endl;
        return ;
    }
    B *classB = dynamic_cast<B*>(p);
    if(classB)
    {
        std::cout << "B" << std::endl;
        return ;
    }
    C *classC = dynamic_cast<C*>(p);
    if(classC)
    {
        std::cout << "C" << std::endl;
        return ;
    }
}

void identify(Base& p)
{
    bool identified = false;
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" <<std::endl;
        identified = true;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    if(!identified)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" <<std::endl;
            identified = true;
        }
        catch(const std::exception& e)
        {
            (void)e;
        }
    }
    if(!identified)
    {
        try
        {
            (void)dynamic_cast<C&>(p);
            std::cout << "C" <<std::endl;
        }
        catch(const std::exception& e)
        {
            (void)e;
        }
    }
}

int main() {
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
}