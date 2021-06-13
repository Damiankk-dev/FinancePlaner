#include "BalanceCreator.h"

//void BalanceCreator::showBalanceByGivenPeriod();
//void BalanceCreator::sortBalanceByDateOldest();
//void BalanceCreator::showCashflowTable();
//
//float BalanceCreator::calculateBalance();
//float BalanceCreator::calculateIncome(){
//
//}
float BalanceCreator::calculateBalance(){
    return calculateCashflow(incomes) - calculateCashflow(expenses);
}

float BalanceCreator::calculateCashflow(std::vector<Cashflow> &cahsflowToCalculate){
    float sum = 0.0;
    for (std::vector<Cashflow>::iterator itr = cahsflowToCalculate.begin(), finish = cahsflowToCalculate.end();
    itr != finish; itr++){
        sum += itr->getValue();
    }
    return sum;
}
void BalanceCreator::showBalanceByGivenPeriod(){
    loadCasfhlowsFromFileByGivenPeriod();
    std::cout << "\nWydatki:\n";
    showCashflowTable(expenses);
    std::cout << "\nPrzychody:\n";
    showCashflowTable(incomes);
    std::cout << "\nBalance: " << calculateBalance() << std::endl;
    system("pause");
}
void BalanceCreator::showBalanceFromCurrentMonth(){

}

void BalanceCreator::loadCasfhlowsFromFileByGivenPeriod(){
    incomes = incomesFile.loadSignedInUserCashflowFromFile(SIGNED_IN_USER_ID);
    expenses = expensesFile.loadSignedInUserCashflowFromFile(SIGNED_IN_USER_ID);
    limitCashflowByGivenPeriod(expenses);
    limitCashflowByGivenPeriod(incomes);
    sortCashflowByDateOldest(incomes);
    sortCashflowByDateOldest(expenses);
}

void BalanceCreator::showCashflowTable(std::vector<Cashflow> &cahsflowToShow){
    std::cout << std::endl << "L.p. " << " | " << " data " << " | " << " wartosc " << " | " << " nazwa "  << std::endl;
    int i = 1;
    for (std::vector<Cashflow>::iterator itr = cahsflowToShow.begin(), finish = cahsflowToShow.end();
    itr != finish; itr++){
        std::cout << i++ << " | "
        << itr->getDate() << " | "
        << itr->getValue() << " | "
        << itr->getLabel() << std::endl;
    }
    std::cout << "\t   Suma: " << calculateCashflow(cahsflowToShow) << std::endl;
}

void BalanceCreator::sortCashflowByDateOldest(std::vector<Cashflow> &cashflowToSort){
    sort(cashflowToSort.begin(), cashflowToSort.end(), isCashflow1Older);
}

bool BalanceCreator::isDateInPeriod(std::string givenDate, std::string givenPeriod){
    std::vector<std::string> period = AuxiliaryMethods::splitStringWithDelim(givenPeriod, '|');
    std::string lowerThresholdDate = period[0];
    std::string upperThresholdDate = period[1];
    return !( (AuxiliaryMethods::isDate1Older(givenDate, lowerThresholdDate ) )
        || AuxiliaryMethods::isDate1Older(upperThresholdDate, givenDate) );
}
bool BalanceCreator::isCashflow1Older(Cashflow c1, Cashflow c2){
    return AuxiliaryMethods::isDate1Older(c1.getDate(), c2.getDate());
}

void BalanceCreator::limitCashflowByGivenPeriod(std::vector<Cashflow> &cahsflowToLimit){
    std::vector<Cashflow> limitedExpenses;

    for (std::vector<Cashflow>::iterator itr = cahsflowToLimit.begin(), finish = cahsflowToLimit.end();
    itr != finish; itr++){
        std::string currentCashflowDate = itr->getDate();
        if (isDateInPeriod(currentCashflowDate, balancePeriod) ) limitedExpenses.push_back(*itr);
    }
    cahsflowToLimit = limitedExpenses;
}
