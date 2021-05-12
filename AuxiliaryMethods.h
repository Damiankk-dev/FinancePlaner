#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <iostream>
#include<ctime>
#include <sstream>
#include <vector>

class AuxiliaryMethods{
public:
    static void changeCommaToPeriod(std::string&);

    static bool isNumber(const std::string& s);

    static char readChar();

    static int convertString2Int(std::string);

    static float readFloat();

    static std::string convertDate2String(time_t);
    static std::string convertInt2String(int);
    static std::string convert2String();
    static std::string readLine();
    static std::string convertFloat2String( float );
    static std::vector<std::string> splitStringWithDelim( std::string, char );

    static time_t convertString2Date(std::string);
private:
    void split(const std::string &s, char delim, std::vector<std::string> &elems);
    bool isYearValueOK(int);
    bool isMonthValueOK(int);
    bool isDayValueOK(int);

};

#endif // AUXILIARY_METHODS_H
