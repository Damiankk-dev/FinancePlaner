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
    this->AddElem( "VALUE", AuxiliaryMethods::convertFloat2String ( cashflow->getValue() ) );
    this->AddElem( "LABEL", cashflow->getLabel() );
    this->AddElem( "DATE", cashflow->getDate() );
    this->Save(this->getFilename());
    this->ResetPos();
}
//std::vector<Cashflow> CashflowFile::getCashflowTableByPeriod(){}
void CashflowFile::getLastCashflowIDFromFile(int signedInUserId){
    lastCashflowId = 0;
    CashflowFile *loadedFile = this;
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
std::vector<Cashflow> CashflowFile::loadSignedInUserCashflowFromFile(int signedInUserId){
    std::vector<Cashflow> cashflows;
    Cashflow newCashflow(signedInUserId);
    CashflowFile *loadedFile = this;
    loadedFile->Load(loadedFile->getFilename() );
    loadedFile->resetPositionAndMoveIntoRoot();
    while (loadedFile->FindElem( "CASHFLOW" ) ){
        loadedFile->IntoElem();
        loadedFile->FindElem( "USER_ID" );
            if (stoi ( this->GetData() ) == signedInUserId ){
                loadedFile->FindElem( "ID" );
                newCashflow.setId( stoi ( this->GetData() ) );
                loadedFile->FindElem( "VALUE" );
                newCashflow.setValue( stod ( this->GetData() ) );
                loadedFile->FindElem( "LABEL" );
                newCashflow.setLabel( this->GetData() );
                loadedFile->FindElem( "DATE" );
                newCashflow.setDate( this->GetData() );
                cashflows.push_back(newCashflow);
            }
        loadedFile->OutOfElem();
    }
    return cashflows;
}
