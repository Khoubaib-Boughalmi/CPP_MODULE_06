#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib> 
#include <cerrno>

# define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

enum scalarTypes {
    CHAR_TYPE,
    DECIMAL_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    PINF_TYPE,
    MINF_TYPE,
    NO_TYPE
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        const ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(std::string value);
        ~ScalarConverter();
        class ErrorExeption: public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif