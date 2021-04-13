#include <iostream>

#include "Markup.h"

using namespace std;

int main()
{
    //TODO: plik xml z uzytwkonikami
    cout << "Hello world!" << endl;
    CMarkup xml;
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem( "root" );
    xml.IntoElem();
    xml.Save("users.xml");
    return 0;
}
