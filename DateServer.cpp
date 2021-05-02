#include "DateServer.h"
//
std::string DateServer::getDateInProperFormat()
{
    AuxiliaryMethods auxiliaryMethods;

    while( true ){
        std::cout << "Podaj date we wlsaciwym formacie (rrrr-mm-dd): ";
        std::string givenDate = auxiliaryMethods.readLine();
        if (isDateFormatProper(givenDate)) return givenDate;
    }

}
//
//bool isDateCorrect();
//bool isDateAfter2000();
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
//
//std::string getTodayDate();
//std::string readSystemDate();
//std::string isDateBefereEndOfCurrentMonth();
