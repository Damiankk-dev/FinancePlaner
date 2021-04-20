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
    this->IntoElem();
    this->Save( FILENAME );
    this->isFileEmpty = true;
}
bool XMLFile::isFileContain(std::string anyParentElement){
    if ( this->isFileInitializedProperly() ) {
        if (this->FindElem(anyParentElement) ) return true;
        else return false;
    } else return false;
}
void XMLFile::resetPositionAndMoveIntoRoot(){
    this->ResetPos();
    this->FindElem("root");
    this->IntoElem();
}
