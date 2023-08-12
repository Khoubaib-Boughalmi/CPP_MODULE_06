#include "ScalarConverter.h"

int isDigits(std::string input) {
    int i = 0;
    while (input[i])
    {
        if(!std::isdigit(input[i]))
            return (0);
        i++;
    }
    return (1);
}

int detectChar(std::string input)
{
    if(input.length() == 1 && !isDigits(input))
        return (1);
    return (0);
}

int detectDecimal(std::string input)
{
    if(isDigits(input))
        return (1);
    return (0);
}

int detectFloat(std::string input)
{
    int i = 0;
    while (input[i] && std::isdigit(input[i]))
        i++;
    if(input[i] == '.')
        i++;
    while (input[i] && std::isdigit(input[i]))
        i++;
    if(input[i] == 'f')
        i++;
    if(!input[i])
        return (1);
    return (0);
}

int detectDouble(std::string input)
{
    int i = 0;
    while (input[i] && std::isdigit(input[i]))
        i++;
    if(input[i] == '.')
        i++;
    while (input[i] && std::isdigit(input[i]))
        i++;
    if(!input[i])
        return (1);
    return (0);}

int detectScalarType(std::string input)
{
    if(detectChar(input))
        return CHAR_TYPE;
    else if(detectDecimal(input))
        return DECIMAL_TYPE;
    else if(detectDouble(input))
        return DOUBLE_TYPE;
    else if(detectFloat(input))
        return FLOAT_TYPE;
    else return NO_TYPE;
    return (0);
}

char convertChar(std::string input) {
    return input[0];
}
char convertDecimal(std::string input) {
    char *ptr;

    errno = 0;
    long result;
    result = std::strtol(input.c_str(), &ptr, 10);
    if(!*ptr)
        return (result);
    if(errno == ERANGE)
        throw;
    return (result);
}
char convertFloat(std::string input) {}
char convertDouble(std::string input) {}

int main(int argc, char *argv[])
{
    (void)argv;
    if(argc != 2)
    {
        std::cout << RED << "Invalid arguments" << std::endl;
        return (1);
    }
    int scalarType = detectScalarType(static_cast<std::string>(argv[1]));
    std::cout << scalarType << std::endl;
    switch (scalarType)
    {
        case CHAR_TYPE:
            convertChar(argv[1]);
            break;
        case DECIMAL_TYPE:
            convertDecimal(argv[1]);
            break;
        case FLOAT_TYPE:
            convertFloat(argv[1]);
            break;
        case DOUBLE_TYPE:
            convertDouble(argv[1]);
            break;
        case NO_TYPE:
        std::cout << "impossible" << std::endl;
    }
   
    return (0);
}