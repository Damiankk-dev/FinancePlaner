#include "xmlFile.h"

bool XMLFile::isFileInitializedProperly(){
//    CMarkup xml;
    bool isXMLInitializedProperly = this->Load( FILENAME ); //zwraca true, gdy plik ma root
    if (!isXMLInitializedProperly) {
        initializeFile();
    }
    isXMLInitializedProperly = this->Load( FILENAME );
    if (!isXMLInitializedProperly) {
        std::cout << "Unable to initialize file\n";
    }
    return isXMLInitializedProperly;
}

std::string XMLFile::getFilename(){
    return FILENAME;
}

void XMLFile::initializeFile(){
    this->SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    this->AddElem("root");
    this->Save( FILENAME );
}
