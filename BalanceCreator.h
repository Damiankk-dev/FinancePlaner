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
    //tests

    void loadCasfhlowsFromFileByGivenPeriod();

private:
    std::vector<Cashflow> incomes;
    std::vector<Cashflow> expenses;

    CashflowFile incomesFile;
    CashflowFile expensesFile;

    void sortBalanceByDateOldest();
    void showCashflowTable();
    void limitCashflowByGivenPeriod(std::vector<Cashflow> &cahsflowToLimit);

    float calculateBalance();
    float calculateCashflow(std::vector<Cashflow>&);

    bool isDate1Older( std::string, std::string );
    bool isDateInPeriod(std::string, std::string );
};

#endif // BALANCE_CREATOR_H
