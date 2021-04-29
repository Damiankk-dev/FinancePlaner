#ifndef DATE_SERVER_H
#define DATE_SERVER_H

#include <iostream>

class DateServer{
public:
    std::string getDateInProperFormat();

    bool isDateCorrect();
    bool isDateAfter2000();
    bool isDateFormatProper();

    std::string getTodayDate();
    std::string readSystemDate();
    std::string isDateBefereEndOfCurrentMonth();
};

#endif // DATE_SERVER_H
