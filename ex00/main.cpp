#include "ScalarConverter.h"

const char *ScalarConverter::ErrorExeption::what() const throw() {
    return "impossible";
}

int isDigits(std::string input) {
    int i = 0;
    if(input[i] == '+' || input[i] == '-' )
        i++;
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
    if(input[i] == '+' || input[i] == '-' )
        i++;
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
    if(input[i] == '+' || input[i] == '-' )
        i++;
    while (input[i] && std::isdigit(input[i]))
        i++;
    if(input[i] == '.')
        i++;
    while (input[i] && std::isdigit(input[i]))
        i++;
    if(!input[i])
        return (1);
    return (0);
}

int detectPlusInf(std::string input)
{
    if(input == "+inf" || input == "+inff")
        return (1);
    return (0);
}

int detectMinusInf(std::string input)
{
    if(input == "-inf" || input == "-inff")
        return (1);
    return (0);
}

scalarTypes detectScalarType(std::string input)
{
    if(detectPlusInf(input))
        return PINF_TYPE;
    if(detectMinusInf(input))
        return MINF_TYPE;
    else if(detectChar(input))
        return CHAR_TYPE;
    else if(detectDecimal(input))
        return DECIMAL_TYPE;
    else if(detectDouble(input))
        return DOUBLE_TYPE;
    else if(detectFloat(input))
        return FLOAT_TYPE;
    else return NO_TYPE;
}

void convertChar(std::string input) {
    char *ptr;

    errno = 0;
    long result;
    result = std::strtol(input.c_str(), &ptr, 10);
    if(errno == ERANGE)
        throw ScalarConverter::ErrorExeption();
    if(result > 31 && result <= 127)
        std::cout << "Char: " << GREEN << "'" << static_cast<char>(result) << "'" << RESET << std::endl;
    else if(result >= 0 && result <= 31)
        std::cout << "Char: " << RED << "Non displayable" << RESET << std::endl;
    else
        throw ScalarConverter::ErrorExeption();

}
void convertDecimal(std::string input) {
    char *ptr;

    errno = 0;
    long result;
    result = std::strtol(input.c_str(), &ptr, 10);
    if(errno == ERANGE)
        throw ScalarConverter::ErrorExeption();
    std::cout << "Decimal: " << GREEN << result << RESET << std::endl;
}

void convertFloat(std::string input) {
    char *ptr;

    errno = 0;
    float result;
    result = std::strtof(input.c_str(), &ptr);
    if(errno == ERANGE)
        throw ScalarConverter::ErrorExeption();
    if(result - static_cast<int>(result) == 0)
        std::cout << "Float: " << GREEN << result << ".0f" << RESET << std::endl;
    else
        std::cout << "Float: " << GREEN << result << "f" << RESET << std::endl;
}

void convertDouble(std::string input) {
    char *ptr;

    errno = 0;
    double result;
    result = std::strtod(input.c_str(), &ptr);
    if(errno == ERANGE)
        throw ScalarConverter::ErrorExeption();
    if(result - static_cast<int>(result) == 0)
        std::cout << "Double: " << GREEN << result << ".0" << RESET << std::endl;
    else
        std::cout << "Double: " << GREEN << result << RESET << std::endl;
}

void displayConversion(scalarTypes scalarType, std::string input) {
    if(scalarType == PINF_TYPE || scalarType == MINF_TYPE)
    {
        if(scalarType == PINF_TYPE)        
        {
            std::cout << "Char: " << RED << "impossible" << RESET <<std::endl;
            std::cout << "Decimal: " << RED << "impossible" << RESET <<std::endl;
            std::cout << "Float: " << RED << "+inff" << RESET <<std::endl;
            std::cout << "Double: " << RED << "+inf" << RESET <<std::endl;
        }
        else
        {
            std::cout << "Char: " << RED << "impossible" << RESET <<std::endl;
            std::cout << "Decimal: " << RED << "impossible" << RESET <<std::endl;
            std::cout << "Float: " << RED << "-inff" << RESET <<std::endl;
            std::cout << "Double: " << RED << "-inf" << RESET <<std::endl;
        }
    }
    else if(scalarType == NO_TYPE)
    {
        std::cout << "Char: " << RED << "impossible" << RESET <<std::endl;
        std::cout << "Decimal: " << RED << "impossible" << RESET <<std::endl;
        std::cout << "Float: " << RED << "nanf" << RESET <<std::endl;
        std::cout << "Double: " << RED << "nan" << RESET <<std::endl;
    }
    else
    {
        try{ convertChar(input); } catch(const std::exception& e){ std::cout << "Char: " <<  RED << e.what() << RESET << std::endl;}
        try{ convertDecimal(input); } catch(const std::exception& e){ std::cout << "Decimal: " << RED <<  e.what() << RESET << std::endl;}
        try{ convertFloat(input); } catch(const std::exception& e){ std::cout << "Float: " <<  RED << e.what() << RESET << std::endl;}
        try{ convertDouble(input); } catch(const std::exception& e){ std::cout << "Double: " <<  RED << e.what() << RESET << std::endl;}
    }
}

int main(int argc, char *argv[])
{
    (void)argv;
    if(argc != 2)
    {
        std::cout << RED << "Invalid arguments" << std::endl;
        return (1);
    }
    scalarTypes scalarType = detectScalarType(static_cast<std::string>(argv[1]));
    displayConversion(scalarType, argv[1]);
    return (0);
}