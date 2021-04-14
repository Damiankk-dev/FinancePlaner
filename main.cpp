#include <iostream>

#include "Markup.h"

#include "XMLFile.h"

using namespace std;

int main()
{
    //TODO: plik xml z uzytwkonikami
    cout << "Hello world!" << endl;
    XMLFile newXMLFile;
//    XMLFile *newXMLFile;
//    newXMLFile =  new XMLFile("userss.xml");

//    newXMLFile->isFileInitializedProperly();
    newXMLFile.isFileInitializedProperly();

    return 0;
}
