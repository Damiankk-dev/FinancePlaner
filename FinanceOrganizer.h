#ifndef FINANCE_ORGANIZER_H
#define FINANCE_ORGANIZER_H

#include <iostream>
#include <vector>

#include "Cashflow.h"
#include "CashflowCreator.h"

class FinanceOrganizer {
public:
    void createNewCashflow(int, std::string);
    void showBalanceByGivenPeriod(int, std::string);
private:
    std::vector<Cashflow> cashflows;
    const std::string INCEOMES_FILENAME;
    const std::string EXPENSES_FILENAME;
    const int SIGNED_IN_USER_ID;
    FinanceOrganizer(int signedInUserId, std::string incomesFilename, std::string expensesFilename)
    : INCEOMES_FILENAME(incomesFilename)
    , EXPENSES_FILENAME(expensesFilename)
    , SIGNED_IN_USER_ID(signedInUserId)
    {}
};
#endif // FINANCE_ORGANIZER_H
