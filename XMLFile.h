#ifndef XML_FILE
#define XML_FILE

#include <iostream>

#include "Markup.h"

class XMLFile{

const std::string FILENAME;

public:
    XMLFile() : FILENAME("defaultFilename.xml"){}
    XMLFile(std::string filename) : FILENAME(filename){}
    bool isFileInitializedProperly();
    std::string getFilename();
private:
    void initializeFile();
};



#endif // XML_FILE
