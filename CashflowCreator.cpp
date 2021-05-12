#include "CashflowCreator.h"


//void showCasflowData();
void CashflowCreator::addCashflow(){
    Cashflow* newCashflow;
    setNewCashflowData(newCashflow);
}
//
//int setCashflowID();
void CashflowCreator::setNewCashflowData(Cashflow* newCashflow){
    DateServer dateServer;
    newCashflow->setId( setCashflowID() );
    std::cout << "Podaj wartosc: ";
    newCashflow->setValue(AuxiliaryMethods::readFloat());
    std::cout << "Podaj opis: ";
    newCashflow->setLabel(AuxiliaryMethods::readLine());
    newCashflow->setDate(dateServer.getDateInProperFormat());
}

int CashflowCreator::setCashflowID(){
    return cashflowFile.getLastCashflowID(SIGNED_IN_USER_ID);
}
