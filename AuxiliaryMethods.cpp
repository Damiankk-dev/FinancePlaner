#include "AuxiliaryMethods.h"

char AuxiliaryMethods::readChar()
{
    std::string input = "";
    char outChar  = {0};

    while (true)    {
        getline(std::cin, input);

        if (input.length() == 1)        {
            outChar = input[0];
            break;
        }
        std::cout << "To nie jest pojedynczy znak. Wpisz ponownie." << std::endl;
    }
    return outChar;
}

 int AuxiliaryMethods::convertString2Int(std::string number)
{
    int numericInt;
    std::istringstream iss(number);
    iss >> numericInt;

    return numericInt;
}
// int AuxiliaryMethods::readInteger() {}
//
// float AuxiliaryMethods::convertString2Float() {}
//
// std::string AuxiliaryMethods::convertDate2String() {}
// std::string AuxiliaryMethods::convertInt2String() {}
// std::string AuxiliaryMethods::convert2String() {}
// std::string AuxiliaryMethods::changeCommaToPeriod() {}
//
// time_t AuxiliaryMethods::convertString2Date() {}
