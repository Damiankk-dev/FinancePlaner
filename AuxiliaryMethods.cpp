#include "AuxiliaryMethods.h"

char AuxiliaryMethods::readChar()
{
    std::string input = "";
    char outChar  = {0};

    while (true)
    {
        getline(std::cin, input);

        if (input.length() == 1)
        {
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

float AuxiliaryMethods::readFloat()
{
    std::string inputNum = "";
    float number = 0.0;

    while (true)
    {
        getline(std::cin, inputNum);
        changeCommaToPeriod(inputNum);
        try
        {
            number = stof(inputNum) ;
            break;
        }
        catch ( std::exception& )
        {
            std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
            number = 0.0;
        }
    }
    return number;
}
//
// float AuxiliaryMethods::convertString2Float(std::string inputNum) {
//    try
//    {
//        number = stof(inputNum) ;
//    }
//    catch (exception& )
//    {
//        std::cout << "To nie jest liczba. Zwrócona wartoœæ to 0.0" << std::endl;
//        number = 0.0;
//    }
//    return number;
// }
//
 std::string AuxiliaryMethods::convertDate2String( time_t givenDate ) {
     struct tm* timeInfo;
    std::string formatedDate = "";

    timeInfo = localtime( &givenDate );
    formatedDate = convertInt2String(timeInfo->tm_year + 1900) + "-";
    formatedDate += convertInt2String(timeInfo->tm_mon + 1) + "-";
    formatedDate += convertInt2String(timeInfo->tm_mday);

    return formatedDate;

 }
 std::string AuxiliaryMethods::convertInt2String(int givenNumber) {
    std::string numericString = "";

    numericString = std::to_string(givenNumber);

    return numericString;
 }
// std::string AuxiliaryMethods::convert2String() {}

void  AuxiliaryMethods::changeCommaToPeriod(std::string &numberWithComma)
{
    for (int i = 0; i < numberWithComma.length() ; i++)
    {
        if (numberWithComma[i] == ',' )
        {
            numberWithComma[i] = '.';
            break;
        }
    }
}

float AuxiliaryMethods::convertString2Float(std::string inputNum) {
    float number = 0.0;
    number = stof(inputNum) ;
    return number;
}
//
// time_t AuxiliaryMethods::convertString2Date() {}
