#include "CashflowFile.h"

int CashflowFile::getLastCashflowID(int signedInUserId){
    getLastCashflowIDFromFile(signedInUserId);
    return lastCashflowId;
}
void CashflowFile::appendCasflowToFile(Cashflow* cashflow){
    this->resetPositionAndMoveIntoRoot();
    this->AddElem( "CASHFLOW" );
    this->IntoElem();
    this->AddElem( "USER_ID" , cashflow->getSignedInUserId() );
    this->AddElem(  "ID", cashflow->getId() );
    this->AddElem( "VALUE", cashflow->getValue() );
    this->AddElem( "LABEL", cashflow->getLabel() );
    this->AddElem( "DATE", cashflow->getDate() );
    this->Save(this->getFilename());
    this->ResetPos();
}
std::vector<Cashflow> CashflowFile::loadSignedInUserCashflowFromFile(){}
std::vector<Cashflow> CashflowFile::getCashflowTableByPeriod(){}
void CashflowFile::getLastCashflowIDFromFile(int signedInUserId){
    CashflowFile *loadedFile = this;
    lastCashflowId = 0;
    loadedFile->Load(loadedFile->getFilename() );
    loadedFile->resetPositionAndMoveIntoRoot();
    while (loadedFile->FindElem( "CASHFLOW" ) ){
        loadedFile->IntoElem();
        loadedFile->FindElem( "USER_ID" );
            if (stoi ( this->GetData() ) == signedInUserId ){
                loadedFile->FindElem( "ID" );
                lastCashflowId = stoi (this->GetData());
            }
        loadedFile->OutOfElem();
    }
}
Cashflow CashflowFile::getSingleCashflowData(){}
