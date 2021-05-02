#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <iostream>
#include<ctime>
#include<sstream>

class AuxiliaryMethods{
public:
    static bool isNumber(const std::string& s);
    static char readChar();

    static int convertString2Int(std::string);

    static float readFloat();

    static std::string convertDate2String(time_t);
    static std::string convertInt2String(int);
    static std::string convert2String();
    static std::string readLine();

    static void changeCommaToPeriod(std::string&);

    static time_t convertString2Date(std::string);

};

#endif // AUXILIARY_METHODS_H
