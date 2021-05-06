#ifndef CASHFLOW_FILE_H
#define CASHFLOW_FILE_H

#include <iostream>

#include "XMLFile.h"

class CashflowFile : public XMLFile{
public:
    CashflowFile(): XMLFile("defaultFilenamee.xml"){}
    CashflowFile(std::string cashflowFilename): XMLFile(cashflowFilename) {
        isFileInitializedProperly();
    }

};
#endif // CASHFLOW_FILE_H
