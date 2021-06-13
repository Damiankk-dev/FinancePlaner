#ifndef DATE_SERVER_H
#define DATE_SERVER_H

#include <iostream>

#include "AuxiliaryMethods.h"

class DateServer{
public:
    std::string getDateInProperFormat();
    std::string getMonthEdges();
    std::string getCurrentMonthBeginingDate();
    std::string getPastMonthBeginingDate();
    std::string getCurrentMonthEndDate();
    std::string getPastMonthEndDate();
    std::string getTodayDate();

    bool isDateFormatProper(std::string);
    bool isDateConvertible(std::string);
    //tests:


private:

    bool isDateBeforeEndOfCurrentMonth(time_t);
    bool isDateAfter2000(int);
    bool isDateValueInRange(time_t);
    bool isLeap(unsigned year);

    int getLastDayOfMonth(int, int);

    std::string concatenateDate(int, int, int);


    time_t readSystemDate();
};

#endif // DATE_SERVER_H
