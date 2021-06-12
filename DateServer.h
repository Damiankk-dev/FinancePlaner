#ifndef DATE_SERVER_H
#define DATE_SERVER_H

#include <iostream>

#include "AuxiliaryMethods.h"

class DateServer{
public:
    std::string getDateInProperFormat();
    std::string getMonthEdges();

    bool isDateFormatProper(std::string);
    bool isDateConvertible(std::string);
    //tests:
    std::string getCurrentMonthBeginingDate();


private:

    bool isDateBeforeEndOfCurrentMonth(time_t);
    bool isDateAfter2000(int);
    bool isDateValueInRange(time_t);
    bool isLeap(unsigned year);


    std::string getCurrentMonthEndDate();
    std::string getPastMonthBeginingDate();
    std::string getPastMonthEndDate();


    time_t readSystemDate();
};

#endif // DATE_SERVER_H
