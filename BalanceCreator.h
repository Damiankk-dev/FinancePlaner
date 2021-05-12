#ifndef BALANCE_CREATOR_H
#define BALANCE_CREATOR_H

#include <iostream>
#include <vector>

#include "Cashflow.h"


class BalanceCreator{
public:
    const std::string BALANCE_PERIOD;
    BalanceCreator(std::string balancePeriod) : BALANCE_PERIOD(balancePeriod){}
    void showBalanceByGivenPeriod();
    std::string setPeriod();
private:
    void sortBalanceByDateOldest();
    void showCashflowTable();

    float calculateBalance();
    float calculateIncome();
    float calculateExpense();

    std::vector<Cashflow> loadCasfhlowsFromFileByGivenPeriod();
};

#endif // BALANCE_CREATOR_H
