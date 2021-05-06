#include "CashflowFile.h"

int CashflowFile::getLastCashflowID(){

}
void CashflowFile::appendCasflowToFile(Cashflow* cashflow){
    this->resetPositionAndMoveIntoRoot();
    this->AddElem( "USER_ID" , cashflow->getSignedInUserId() );
    this->IntoElem();
    this->AddElem( "CASHFLOW" );
    this->IntoElem();
    this->AddElem(  "ID", cashflow->getId() );
    this->AddElem( "VALUE", cashflow->getValue() );
    this->AddElem( "LABEL", cashflow->getLabel() );
    this->AddElem( "DATE", cashflow->getDate() );
    this->Save(this->getFilename());
    this->ResetPos();
}
std::vector<Cashflow> CashflowFile::loadSignedInUserCashflowFromFile(){}
std::vector<Cashflow> CashflowFile::getCashflowTableByPeriod(){}
int CashflowFile::getLastCashflowIDFromFile(){}
Cashflow CashflowFile::getSingleCashflowData(){}
