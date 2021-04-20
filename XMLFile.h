#ifndef XML_FILE
#define XML_FILE

#include <iostream>

#include "Markup.h"

class XMLFile : public CMarkup{

const std::string FILENAME;

public:
    bool isFileEmpty = true;
    XMLFile() : FILENAME("defaultFilename.xml"){}
    XMLFile(std::string filename) : FILENAME(filename){}
    bool isFileInitializedProperly();
    bool isFileContain(std::string);
    std::string getFilename();
    void resetPositionAndMoveIntoRoot();
private:
    void initializeFile();
};



#endif // XML_FILE
