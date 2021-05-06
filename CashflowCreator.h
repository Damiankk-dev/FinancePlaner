#ifndef CASHFLOW_CREATOR_H
#define CASHFLOW_CREATOR_H

#include <iostream>

#include "AuxiliaryMethods.h"
#include "Cashflow.h"
#include "DateServer.h"


class CashflowCreator{
public:
    CashflowCreator(int signedInUserID) : SIGNED_IN_USER_ID(signedInUserID){};
    void showCasflowData(Cashflow* newCashflow);
    void addCashflow(Cashflow* newCashflow);
    //testy
private:
    const int SIGNED_IN_USER_ID;
    void setNewCashflowData(Cashflow*);
    int setCashflowID();
};


#endif // CASHFLOW_CREATOR_H
