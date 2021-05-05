#ifndef DATE_SERVER_H
#define DATE_SERVER_H

#include <iostream>

#include "AuxiliaryMethods.h"

class DateServer{
public:
    std::string getDateInProperFormat();

    bool isDateFormatProper(std::string);
    bool isDateConvertible(std::string);

private:

    bool isDateBeforeEndOfCurrentMonth(time_t);
    bool isDateAfter2000(int);
    bool isDateValueInRange(time_t);

    time_t readSystemDate();
};

#endif // DATE_SERVER_H
