#include "AuxiliaryMethods.h"

bool AuxiliaryMethods::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool AuxiliaryMethods::isDate1Older(std::string date1, std::string date2){
    time_t ttime1;
    time_t ttime2;
    ttime1 = AuxiliaryMethods::convertString2Date(date1);
    ttime2 = AuxiliaryMethods::convertString2Date(date2);
    return difftime(ttime1, ttime2) <= 0 ;
}

char AuxiliaryMethods::readChar()
{
    std::string input = "";
    char outChar  = {0};

    while (true)
    {
        getline(std::cin, input);

        if (input.length() == 1)
        {
            outChar = input[0];
            break;
        }
        std::cout << "To nie jest pojedynczy znak. Wpisz ponownie." << std::endl;
    }
    return outChar;
}

int AuxiliaryMethods::convertString2Int(std::string number)
{
    int numericInt;
    std::istringstream iss(number);
    iss >> numericInt;

    return numericInt;
}
float AuxiliaryMethods::readFloat()
{
    std::string inputNum = "";
    float number = 0.0;

    while (true)
    {
        getline(std::cin, inputNum);
        changeCommaToPeriod(inputNum);
        try
        {
            number = stof(inputNum) ;
            break;
        }
        catch ( std::exception& )
        {
            std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
            number = 0.0;
        }
    }
    return number;
}

 std::string AuxiliaryMethods::convertDate2String( time_t givenDate ) {
     struct tm* timeInfo;
    std::string formatedDate = "";

    timeInfo = localtime( &givenDate );
    formatedDate = convertInt2String(timeInfo->tm_year + 1900) + "-";
    formatedDate += convertInt2String(timeInfo->tm_mon + 1) + "-";
    formatedDate += convertInt2String(timeInfo->tm_mday);

    return formatedDate;

 }
 std::string AuxiliaryMethods::convertInt2String(int givenNumber) {
    std::string numericString = "";

    numericString = std::to_string(givenNumber);

    return numericString;
 }
std::string AuxiliaryMethods::readLine(){
    std::string newInput = "";
    getline(std::cin, newInput);
    return newInput;
}
std::string AuxiliaryMethods::convertFloat2String( float number ){
    std::ostringstream ss;
    ss << number;
    return ss.str();
}
std::vector<std::string>
AuxiliaryMethods::splitStringWithDelim( const std::string givenString, char delim ){
    AuxiliaryMethods axmthds;
    std::vector<std::string> elems;
    axmthds.split(givenString, delim, elems);
    return elems;
}
void  AuxiliaryMethods::changeCommaToPeriod(std::string &numberWithComma)
{
    for (int i = 0; i < numberWithComma.length() ; i++)
    {
        if (numberWithComma[i] == ',' )
        {
            numberWithComma[i] = '.';
            break;
        }
    }
}

 time_t AuxiliaryMethods::convertString2Date(std::string givenDate) {
    AuxiliaryMethods axmthds;
    int year, month,day;
    time_t ttime;
    struct tm * timeinfo;
    year = stoi(givenDate.substr(0,4));
    month = stoi(givenDate.substr(5,2));
    day = stoi(givenDate.substr(8,2));
    if ( ! (axmthds.isYearValueOK(year) && axmthds.isMonthValueOK(month) && axmthds.isDayValueOK(day) ) ){
        return -1;
    }
    time(&ttime);
    timeinfo = localtime (&ttime);

    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    return mktime(timeinfo);
 }
bool AuxiliaryMethods::isYearValueOK(int year){
    return year > 1900;
}
bool AuxiliaryMethods::isMonthValueOK(int month){
    return month < 13;
}
bool AuxiliaryMethods::isDayValueOK(int day){
    return day < 32;
}

void AuxiliaryMethods::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
