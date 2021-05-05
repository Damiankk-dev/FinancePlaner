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
