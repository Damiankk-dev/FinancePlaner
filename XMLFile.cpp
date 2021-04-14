#include "xmlFile.h"

bool XMLFile::isFileInitializedProperly(){
    CMarkup xml;
    bool isXMLInitializedProperly = xml.Load( FILENAME ); //zwraca true, gdy plik ma root
    if (!isXMLInitializedProperly) {
        initializeFile();
    }
    isXMLInitializedProperly = xml.Load( FILENAME );
    if (!isXMLInitializedProperly) {
        std::cout << "Unable to initialize file\n";
    }
    return isXMLInitializedProperly;
}

std::string XMLFile::getFilename(){
    return FILENAME;
}

void XMLFile::initializeFile(){
    CMarkup xml;
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("root");
    xml.Save( FILENAME );
}
