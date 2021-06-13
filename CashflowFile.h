#ifndef CASHFLOW_FILE_H
#define CASHFLOW_FILE_H

#include <iostream>
#include <vector>

#include "XMLFile.h"
#include "Cashflow.h"

class CashflowFile : public XMLFile{
public:
    CashflowFile(): XMLFile("defaultFilename.xml"){}
    CashflowFile(std::string cashflowFilename): XMLFile(cashflowFilename) {
        isFileInitializedProperly();
    }
    void appendCasflowToFile(Cashflow*);
    int getLastCashflowID(int);
    std::vector<Cashflow> loadSignedInUserCashflowFromFile(int);
    std::vector<Cashflow> getCashflowTableByPeriod();
private:
    void getLastCashflowIDFromFile(int);
    int lastCashflowId;
};
#endif // CASHFLOW_FILE_H
