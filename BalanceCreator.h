#ifndef BALANCE_CREATOR_H
#define BALANCE_CREATOR_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Cashflow.h"
#include "CashflowFile.h"
#include "PeriodServer.h"


class BalanceCreator{
public:
    std::string balancePeriod;
    const int SIGNED_IN_USER_ID;
    BalanceCreator(int signedInUserId, std::string incomeFilename, std::string expenseFilename, std::string periodType)
    : SIGNED_IN_USER_ID(signedInUserId)
    , incomesFile(incomeFilename)
    , expensesFile(expenseFilename)
    {
        PeriodServer periodServer;
        balancePeriod = periodServer.specifyPeriod(periodType);
    }
    void showBalanceByGivenPeriod();
    void showBalanceFromCurrentMonth();
    //tests


private:
    std::vector<Cashflow> incomes;
    std::vector<Cashflow> expenses;

    CashflowFile incomesFile;
    CashflowFile expensesFile;

    void sortCashflowByDateOldest(std::vector<Cashflow>&);
    void showCashflowTable(std::vector<Cashflow>&);
    void limitCashflowByGivenPeriod(std::vector<Cashflow> &cahsflowToLimit);
    void loadCasfhlowsFromFileByGivenPeriod();

    float calculateBalance();
    float calculateCashflow(std::vector<Cashflow>&);

    bool isDateInPeriod(std::string, std::string );
    static bool isCashflow1Older(Cashflow, Cashflow);
};

#endif // BALANCE_CREATOR_H
