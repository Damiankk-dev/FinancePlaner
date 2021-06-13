#include "PeriodServer.h"

std::string PeriodServer::specifyPeriod(std::string periodType){
    std::string specifiedPeriod = "";
    if ( periodType == "current" ){
        specifiedPeriod += getCurrentMonthBeginingDate();
        specifiedPeriod += "|";
        specifiedPeriod += getCurrentMonthEndDate();
    } else if (periodType == "past"){
        specifiedPeriod += getPastMonthBeginingDate();
        specifiedPeriod += "|";
        specifiedPeriod += getPastMonthEndDate();
    } else {
        std::cout << "Okresl daty okresu,\nz ktorego chcesz policzyc bilans\n";

        std::cout << "Podaj dolna granice okresu\n";
        specifiedPeriod = getDateInProperFormat();
        std::cout << "Podaj gorna granice okresu\n";
        specifiedPeriod += "|";
        specifiedPeriod += getDateInProperFormat();
    }
    return specifiedPeriod;
}
