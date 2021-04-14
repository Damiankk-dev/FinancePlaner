#include "xmlFile.h"

bool XMLFile::isFileInitializedProperly(){
    CMarkup xml;
    bool isXMLInitializedProperly = xml.Load( FILENAME ); //zwraca true, gdy plik ma root
    if (isXMLInitializedProperly) {
        std::cout << "Perfect\n";
    } else {
        std::cout << "So badn\n";
        initializeFile();
    }
    isXMLInitializedProperly = xml.Load( FILENAME );
    if (isXMLInitializedProperly) {
        std::cout << "Perfect, opened\n";
    } else {
        std::cout << "So bad, not opened\n";
    }
    return isXMLInitializedProperly;
}


void XMLFile::initializeFile(){
    CMarkup xml;
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("root");
    xml.Save( FILENAME );
}
