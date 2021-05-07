#include "CashflowFile.h"

int CashflowFile::getLastCashflowID(int signedInUserId){
    CashflowFile *loadedFile = this;
    loadedFile->Load(loadedFile->getFilename() );
    loadedFile->resetPositionAndMoveIntoRoot();
    while (loadedFile->FindElem( "USER_ID" ) ){
//        loadedFile->IntoElem();
        std::cout << loadedFile->GetData() << std::endl;
//            if (stoi ( this->GetData() ) == signedInUserId ){
//                std::cout << "cukces\n";
//            }
//        this->isFileEmpty = false;
//        loadedFile->IntoElem();
//        loadedUsers.push_back(getUserData() );
//        loadedFile->OutOfElem();
    }
    return 0;

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
