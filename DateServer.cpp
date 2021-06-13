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

int DateServer::getLastDayOfMonth(int monthNum, int yearNum){
    if ( monthNum < 8 ) {
        if ( monthNum % 2 != 0 ) {
            return 31;
        } else if ( monthNum == 2 ) {
            if ( isLeap(yearNum) ) return 29;
            else return 28;
        } else {
            return 30;
        }
    } else {
        if ( monthNum % 2 != 0 ) {
            return 30;
        } else {
            return 31;
        }
    }
    return 0;
}
std::string DateServer::getCurrentMonthBeginingDate(){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );

    int monthNum = 1 + currentDate->tm_mon;
    int yearNum = 1900 + currentDate->tm_year;
    return concatenateDate(yearNum, monthNum, 1);
}
std::string DateServer::getPastMonthBeginingDate(){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );

    int monthNum = currentDate->tm_mon;
    int yearNum = 1900 + currentDate->tm_year;
    if ( monthNum == 0 ){
        yearNum -= 1;
        monthNum = 12;
        return concatenateDate(yearNum, monthNum, 1);
    } else {
        return concatenateDate(yearNum, monthNum, 1);
    }
}
std::string DateServer::getCurrentMonthEndDate(){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );

    int monthNum = 1 + currentDate->tm_mon;
    int yearNum = 1900 + currentDate->tm_year;
    int lastDayOfMonth = getLastDayOfMonth(monthNum, yearNum);
    return concatenateDate(yearNum, monthNum, lastDayOfMonth);
}
std::string DateServer::getPastMonthEndDate(){
    time_t currentSystemDate = readSystemDate();
    struct tm *currentDate = localtime(&currentSystemDate );

    int monthNum = currentDate->tm_mon;
    int yearNum = 1900 + currentDate->tm_year;
    if ( monthNum == 0 ){
        yearNum -= 1;
        monthNum = 12;
        return concatenateDate(yearNum, monthNum, getLastDayOfMonth(monthNum, yearNum));
    } else {
        return concatenateDate(yearNum, monthNum, getLastDayOfMonth(monthNum, yearNum));
    }

}
std::string DateServer::concatenateDate(int year, int month, int day){
    std::string dateString = "";
    dateString += AuxiliaryMethods::convertInt2String(year);
    dateString += "-";
    if ( month < 10 ) dateString += "0";
    dateString += AuxiliaryMethods::convertInt2String(month);
    dateString += "-";
    if ( day < 10 ) dateString += "0";
    dateString += AuxiliaryMethods::convertInt2String(day);
    return dateString;
}
