#include "ScalarConverter.h"

int main(int argc, char *argv[])
{
    (void)argv;
    if(argc != 2)
    {
        std::cout << RED << "Invalid arguments" << std::endl;
        return (1);
    }
    ScalarConverter::convert(static_cast<std::string>(argv[1]));
    return (0);
}