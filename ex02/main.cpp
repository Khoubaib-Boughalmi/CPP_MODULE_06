#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base * generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int randVal = std::rand() % 3;
    if(randVal == 0)
        return new A();
    if(randVal == 1)
        return new B();
    if(randVal == 2)
        return new C();
    return (0);
}

int main() {
    Base *p = generate();
    A *classA = dynamic_cast<A*>(p);
    if(classA)
    {
        std::cout << "A" << std::endl;
        delete p;
        return (0);
    }
    B *classB = dynamic_cast<B*>(p);
    if(classB)
    {
        std::cout << "B" << std::endl;
        delete p;
        return (0);
    }
    C *classC = dynamic_cast<C*>(p);
    if(classC)
    {
        std::cout << "C" << std::endl;
        delete p;
        return (0);
    }
}