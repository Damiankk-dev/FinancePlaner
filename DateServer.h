#ifndef DATE_SERVER_H
#define DATE_SERVER_H

#include <iostream>

#include "AuxiliaryMethods.h"

class DateServer{
public:
    std::string getDateInProperFormat();

    bool isDateCorrect();
    bool isDateAfter2000(std::string);
    bool isDateFormatProper(std::string);

    std::string getTodayDate();
    std::string readSystemDate();
    std::string isDateBeforeEndOfCurrentMonth();
};

#endif // DATE_SERVER_H
