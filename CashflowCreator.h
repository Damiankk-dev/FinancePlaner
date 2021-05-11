#ifndef CASHFLOW_CREATOR_H
#define CASHFLOW_CREATOR_H

#include <iostream>

#include "FinanceOrganizer.h"
#include "AuxiliaryMethods.h"
#include "Cashflow.h"
#include "DateServer.h"
#include "CashflowFile.h"


class CashflowCreator{
public:
    CashflowCreator(int signedInUserId, std::string cashflowFilename)
    : cashflowFile(cashflowFilename)
    , SIGNED_IN_USER_ID(signedInUserId){}

    void showCasflowData(Cashflow* newCashflow);
    void addCashflow(Cashflow* newCashflow);
    //testy
private:
    CashflowFile cashflowFile;
    const int SIGNED_IN_USER_ID;
    void setNewCashflowData(Cashflow*);
    int setCashflowID();
};


#endif // CASHFLOW_CREATOR_H
