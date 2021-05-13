#ifndef BALANCE_CREATOR_H
#define BALANCE_CREATOR_H

#include <iostream>
#include <vector>

#include "Cashflow.h"
#include "CashflowFile.h"
#include "PeriodServer.h"


class BalanceCreator{
public:
    std::string balancePeriod;
    const int SIGNED_IN_USER_ID;
    BalanceCreator(int signedInUserId, std::string incomeFilename, std::string expenseFilename)
    : SIGNED_IN_USER_ID(signedInUserId)
    , incomesFile(incomeFilename)
    , expensesFile(expenseFilename)
    {
        PeriodServer periodServer;
        balancePeriod = periodServer.specifyPeriod();
    }
    void showBalanceByGivenPeriod();
private:
    std::vector<Cashflow> incomes;
    std::vector<Cashflow> expenses;

    CashflowFile incomesFile;
    CashflowFile expensesFile;

    void sortBalanceByDateOldest();
    void showCashflowTable();

    float calculateBalance();
    float calculateIncome();
    float calculateExpense();

    void loadCasfhlowsFromFileByGivenPeriod();
    bool isDate1Older( std::string , std::string );
};

#endif // BALANCE_CREATOR_H