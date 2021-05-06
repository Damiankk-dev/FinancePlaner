#ifndef CASHFLOW_FILE_H
#define CASHFLOW_FILE_H

#include <iostream>
#include <vector>

#include "XMLFile.h"
#include "Cashflow.h"

class CashflowFile : public XMLFile{
public:
    CashflowFile(): XMLFile("defaultFilenamee.xml"){}
    CashflowFile(std::string cashflowFilename): XMLFile(cashflowFilename) {
        isFileInitializedProperly();
    }
    int getLastCashflowID();
    void appendCasflowToFile();
    std::vector<Cashflow> loadSignedInUserCashflowFromFile();
    std::vector<Cashflow> getCashflowTableByPeriod();
private:
    int getLastCashflowIDFromFile();
    Cashflow getSingleCashflowData();

};
#endif // CASHFLOW_FILE_H
