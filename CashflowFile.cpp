#include "CashflowFile.h"

int CashflowFile::getLastCashflowID(int signedInUserId){
    CashflowFile *loadedFile = this;
    int cashflowId = 0;
    loadedFile->Load(loadedFile->getFilename() );
    loadedFile->resetPositionAndMoveIntoRoot();
    while (loadedFile->FindElem( "CASHFLOW" ) ){
        loadedFile->IntoElem();
        loadedFile->FindElem( "USER_ID" );
            if (stoi ( this->GetData() ) == signedInUserId ){
                loadedFile->FindElem( "ID" );
                cashflowId = stoi (this->GetData());
            }
        loadedFile->OutOfElem();
    }
    return cashflowId;

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
int CashflowFile::getLastCashflowIDFromFile(){}
Cashflow CashflowFile::getSingleCashflowData(){}
