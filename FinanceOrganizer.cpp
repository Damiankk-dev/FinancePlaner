#include "FinanceOrganizer.h"

void FinanceOrganizer::createNewCashflow(int signedInUserId, std::string cashflowFilename){
    CashflowCreator cashflowCreator(signedInUserId, cashflowFilename);
    cashflowCreator.addCashflow();
}

void FinanceOrganizer::showBalanceByGivenPeriod(int signedInUserId, std::string periodType){
    BalanceCreator newBalance( signedInUserId, INCEOMES_FILENAME, EXPENSES_FILENAME, periodType);
    newBalance.showBalanceByGivenPeriod();
}
