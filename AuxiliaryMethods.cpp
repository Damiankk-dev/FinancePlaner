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

 float AuxiliaryMethods::readFloat() {
    std::string inputNum = "";
    float number = 0.0;

    while (true)    {
        getline(std::cin, inputNum);
        changeCommaToPeriod(&inputNum);
        std::stringstream myStream(inputNum);
//        number = std::stof(inputNum);

        if (myStream>>number) break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    return number;
 }
//
// float AuxiliaryMethods::convertString2Float() {}
//
// std::string AuxiliaryMethods::convertDate2String() {}
// std::string AuxiliaryMethods::convertInt2String() {}
// std::string AuxiliaryMethods::convert2String() {}

 void  AuxiliaryMethods::changeCommaToPeriod(std::string* numberWithComma) {
     std::string changedNumber = *numberWithComma;
    std::cout << "znak przed zmiana" << changedNumber << std::endl;
     for (int i = 0; i < changedNumber.length() ; i++){
        if (changedNumber[i] == ',' ) {
                changedNumber[i] = '.';
                break;
        }
     }
    std::cout << "znak po zmiana" << changedNumber << std::endl;
 }
//
// time_t AuxiliaryMethods::convertString2Date() {}
