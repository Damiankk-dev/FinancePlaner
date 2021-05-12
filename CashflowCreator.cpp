#include "CashflowCreator.h"


//void showCasflowData();
void CashflowCreator::addCashflow(){
    Cashflow* newCashflow;
    Cashflow cashflow(SIGNED_IN_USER_ID);
    newCashflow = &cashflow;
    setNewCashflowData(newCashflow);
}
//
//int setCashflowID();
void CashflowCreator::setNewCashflowData(Cashflow* newCashflow){
    DateServer dateServer;
    newCashflow->setId( setCashflowID() + 1 );
    std::cout << "Podaj wartosc: ";
    newCashflow->setValue(AuxiliaryMethods::readFloat());
    std::cout << "Podaj opis: ";
    newCashflow->setLabel(AuxiliaryMethods::readLine());
    newCashflow->setDate(dateServer.getDateInProperFormat());
    cashflowFile.appendCasflowToFile(newCashflow);
}

int CashflowCreator::setCashflowID(){
    return cashflowFile.getLastCashflowID(SIGNED_IN_USER_ID);
}
