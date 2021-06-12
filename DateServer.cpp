#include "DateServer.h"
//
std::string DateServer::getDateInProperFormat()
{
    AuxiliaryMethods auxiliaryMethods;

    while( true ){
        std::cout << "Podaj date z zakresu 2000-01-01\ndo konca aktualnego miesiaca\nwe wlasciwym formacie (rrrr-mm-dd): ";
        std::string givenDate = auxiliaryMethods.readLine();
        if (isDateFormatProper(givenDate)) {
            if (isDateConvertible(givenDate)){
                time_t givenDateT = auxiliaryMethods.convertString2Date(givenDate);
                if (isDateValueInRange(givenDateT) ) return givenDate;
            }
        }
    }
}
bool DateServer::isDateAfter2000(int givenDateYear){
    const int YEAR_TRESHOLD = 2000;
    return givenDateYear > YEAR_TRESHOLD;
}
bool DateServer::isDateFormatProper(std::string dateToCheck)
{
    if ( dateToCheck.length() != 10  )
    {
        std::cout << "\n Niepoprawny format daty\n";
        return false;
    }
    else
    {
        std::string year, month, day, yearSeparator, monthSeparator;
        yearSeparator = dateToCheck[4];
        monthSeparator = dateToCheck[7];
        year = dateToCheck.substr(0, 4);
        month = dateToCheck.substr(5, 2);
        day = dateToCheck.substr(8, 2);
        if ( yearSeparator != "-" || monthSeparator != "-" )
        {
            std::cout << "\n Niepoprawny separator lat lub miesiecy\n";
            return false;
        }
        else if  ( !(AuxiliaryMethods::isNumber(year)) || !(AuxiliaryMethods::isNumber(month)) || !(AuxiliaryMethods::isNumber(day)) )
        {
            std::cout << "\n Niepoprawny format skladowych daty\n";
            return false;
        } else return true;
    }
}
time_t DateServer::readSystemDate(){
    time_t curTime = time(NULL);
    return curTime;
}
bool DateServer::isDateBeforeEndOfCurrentMonth(time_t givenDate){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );
    struct tm *givenDateDetailed = localtime(&givenDate) ;
    return givenDateDetailed->tm_year == currentDate->tm_year && givenDateDetailed->tm_mon<=currentDate->tm_mon;
}
bool DateServer::isDateConvertible(std::string givenDate){
    return AuxiliaryMethods::convertString2Date(givenDate) != -1;
}
bool DateServer::isDateValueInRange(time_t givenDate){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );
    struct tm * givenDateDetailed;
    givenDateDetailed = localtime(&givenDate);
    if (givenDateDetailed->tm_year == currentDate->tm_year )
        return isDateAfter2000(givenDateDetailed->tm_year + 1900) && isDateBeforeEndOfCurrentMonth(givenDate);
    else
        return isDateAfter2000(givenDateDetailed->tm_year + 1900);
}

bool DateServer::isLeap(unsigned year) {
    if (((year%4 == 0)&& (year%100 != 0)) || (year%400 == 0)) return true;
    else return false ;
}

std::string DateServer::getCurrentMonthBeginingDate(){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );

    int monthNum = 1 + currentDate->tm_mon;
    int yearNum = 1900 + currentDate->tm_year;
    std::string currentMonthBegDate = AuxiliaryMethods::convertInt2String(yearNum);
    currentMonthBegDate += "-";
    currentMonthBegDate += AuxiliaryMethods::convertInt2String(monthNum);
    currentMonthBegDate += "-01";
    std::cout << "Poczatek aktualnego mieiaca: " << currentMonthBegDate << "\n";
    return currentMonthBegDate;
//    if ( monthNum < 8 ) {
//        if ( monthNum % 2 != 0 ) {
//            daysInMonth = 31;
//        } else if ( monthNum == 2 ) {
//            if ( isLeap(yearNum) ) daysInMonth = 29;
//            else daysInMonth = 28;
//        } else {
//            daysInMonth = 30;
//        }
//    } else {
//        if ( monthNum % 2 != 0 ) {
//            daysInMonth = 30;
//        } else {
//            daysInMonth = 31;
//        }
//    }
}
std::string DateServer::getPastMonthBeginingDate(){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );

    int monthNum = 1 + currentDate->tm_mon - 1;
    int yearNum = 1900 + currentDate->tm_year;
        std::string currentMonthBegDate = "";
    if (monthNum != 0){
        currentMonthBegDate += AuxiliaryMethods::convertInt2String(yearNum);
        currentMonthBegDate += "-";
        currentMonthBegDate += AuxiliaryMethods::convertInt2String(monthNum);
        currentMonthBegDate += "-01";
        std::cout << "Poczatek poprzedniego mieiaca: " << currentMonthBegDate << "\n";
    } else {
        monthNum = 12;
        yearNum -= 1;
        currentMonthBegDate += AuxiliaryMethods::convertInt2String(yearNum);
        currentMonthBegDate += "-";
        currentMonthBegDate += AuxiliaryMethods::convertInt2String(monthNum);
        currentMonthBegDate += "-01";
        std::cout << "Poczatek poprzedniego mieiaca: " << currentMonthBegDate << "\n";
    }
    return currentMonthBegDate;
}
