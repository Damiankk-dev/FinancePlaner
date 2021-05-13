#include "BalanceCreator.h"

//void BalanceCreator::showBalanceByGivenPeriod();
//void BalanceCreator::sortBalanceByDateOldest();
//void BalanceCreator::showCashflowTable();
//
//float BalanceCreator::calculateBalance();
//float BalanceCreator::calculateIncome();
//float BalanceCreator::calculateExpense();
//
//TODO: Testy dzia³ania metody
//TODO: Rozbicie na mniejsze metody
void BalanceCreator::loadCasfhlowsFromFileByGivenPeriod(){
    incomes = incomesFile.loadSignedInUserCashflowFromFile(SIGNED_IN_USER_ID);
    expenses = expensesFile.loadSignedInUserCashflowFromFile(SIGNED_IN_USER_ID);

    std::vector<Cashflow> loadedCashflows;
    std::vector<std::string> givenPeriod = AuxiliaryMethods::splitStringWithDelim(balancePeriod, '|');

    for (std::vector<Cashflow>::iterator itr = incomes.begin(), finish = incomes.end();
    itr != finish; itr++){
        std::string currentCashflowDate = itr->getDate();
        std::string lowerThresholdDate = givenPeriod[0];
        std::string upperThresholdDate = givenPeriod[1];
        if ( (isDate1Older(currentCashflowDate, lowerThresholdDate ) )
            && isDate1Older(upperThresholdDate, currentCashflowDate) ) {
                incomes.erase(itr);
            }
    }

}

bool BalanceCreator::isDate1Older(std::string date1, std::string date2){
    time_t ttime1;
    time_t ttime2;
    ttime1 = AuxiliaryMethods::convertString2Date(date1);
    ttime2 = AuxiliaryMethods::convertString2Date(date2);
    return difftime(ttime1, ttime2) <= 0 ;
}
