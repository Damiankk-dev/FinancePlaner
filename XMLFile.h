#ifndef XML_FILE
#define XML_FILE

#include <iostream>

#include "Markup.h"

class XMLFile : public CMarkup{

const std::string FILENAME;

public:
    XMLFile() : FILENAME("defaultFilename.xml"){}
    XMLFile(std::string filename) : FILENAME(filename){}
    void resetPositionAndMoveIntoRoot();
    bool isFileEmpty = true;
    bool isFileInitializedProperly();
    bool isFileContain(std::string);
    std::string getFilename();
private:
    void initializeFile();
};
#endif // XML_FILE
