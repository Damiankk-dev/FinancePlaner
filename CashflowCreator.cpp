#include "CashflowCreator.h"


//void showCasflowData();
void CashflowCreator::addCashflow(Cashflow* newCashflow){
    setNewCashflowData(newCashflow);
}
//
//int setCashflowID();
void CashflowCreator::setNewCashflowData(Cashflow* newCashflow){
    DateServer dateServer;
    std::cout << "Podaj wartosc: ";
    newCashflow->setValue(AuxiliaryMethods::readFloat());
    std::cout << "Podaj opis: ";
    newCashflow->setLabel(AuxiliaryMethods::readLine());
    newCashflow->setDate(dateServer.getDateInProperFormat());
}

int CashflowCreator::setCashflowID(){

}
