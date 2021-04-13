#include "xmlFile.h"

bool isFileInitializedProperly(){
    CMarkup xml;
    bool isXMLInitializedProperly = xml.Load( "useros.xml" ); //zwraca true, gdy plik ma root
    if (isXMLInitializedProperly) {
        std::cout << "Perfect\n";
    } else {
        std::cout << "So badn\n";
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("root");
        xml.Save("useros.xml");
    }
    isXMLInitializedProperly = xml.Load( "useros.xml" );
    if (isXMLInitializedProperly) {
        std::cout << "Perfect, opened\n";
    } else {
        std::cout << "So bad, not opened\n";
    }
    return isXMLInitializedProperly;
}
