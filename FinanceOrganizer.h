#ifndef FINANCE_ORGANIZER_H
#define FINANCE_ORGANIZER_H

#include <iostream>
#include <vector>

#include "Cashflow.h"
#include "CashflowCreator.h"
#include "BalanceCreator.h"

class FinanceOrganizer {
public:
    FinanceOrganizer( int signedInUserId, std::string incomesFilename, std::string expensesFilename)
    : INCEOMES_FILENAME(incomesFilename)
    , EXPENSES_FILENAME(expensesFilename)
    , SIGNED_IN_USER_ID(signedInUserId)
    {}
    void createNewCashflow(int, std::string);
    void showBalanceByGivenPeriod(int, std::string = "any");
private:
    std::vector<Cashflow> cashflows;
    const std::string INCEOMES_FILENAME;
    const std::string EXPENSES_FILENAME;
    const int SIGNED_IN_USER_ID;
};
#endif // FINANCE_ORGANIZER_H
