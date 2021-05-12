#include "FinanceOrganizer.h"

void FinanceOrganizer::createNewCashflow(int signedInUserId, std::string cashflowFilename){
    CashflowCreator cashflowCreator(signedInUserId, cashflowFilename);
    cashflowCreator.addCashflow();
}
