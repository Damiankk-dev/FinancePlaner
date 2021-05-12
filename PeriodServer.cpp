#include "PeriodServer.h"

std::string PeriodServer::specifyPeriod(){
    std::string specifiedPeriod = "";
    std::cout << "Okresl daty okresu,\nz ktorego chcesz policzyc bilans\n";

    std::cout << "Podaj dolna granice okresu\n";
    specifiedPeriod = getDateInProperFormat();
    std::cout << "Podaj gorna granice okresu\n";
    specifiedPeriod += "|";
    specifiedPeriod += getDateInProperFormat();
    return specifiedPeriod;
}
