#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
# define RED "\033[31m"

class ScalarConverter
{
private:
    ScalarConverter();
public:
    static void convert(std::string value);
    ~ScalarConverter();
};



#endif