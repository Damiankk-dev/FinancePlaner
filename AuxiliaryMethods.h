#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <iostream>
#include<ctime>
#include<sstream>

class AuxiliaryMethods{
public:
    static char readChar();

    static int convertString2Int(std::string);
    static int readInteger();

    static float convertString2Float();

    static std::string convertDate2String();
    static std::string convertInt2String();
    static std::string convert2String();
    static std::string changeCommaToPeriod();

    static time_t convertString2Date();

};

#endif // AUXILIARY_METHODS_H
