#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <iostream>
#include <string>
using namespace std;

#include "Document.h"
#include "Element.h"
using namespace yazi::xml;

int main()
{
    // read a xml string from file
    const string filename = "./main.xml";
    Document doc;
    doc.load_file(filename);
    Element root = doc.parse();
    std::cout << root.toString() << std::endl;

    // loop over root's child element
    for (Element::const_iterator it = root.begin(); it != root.end(); it++)
    {
        std::cout << (*it).toString() << std::endl;
    }

    // fetch the root's first child element which's name is matched student
    const Element & student = root["student"];

    // loop over student's child element
    for (Element::const_iterator it = student.begin(); it != student.end(); it++)
    {
        std::cout << (*it).toString() << std::endl;
    }

    // create a xml element
    Element elem;

    // set the elem's name
    elem.name("root");

    // set the elem's attr
    elem.attr("id", "1");
    elem.attr("class", "101");

    // get the elem's name
    const string & name = elem.name();

    // get the elem's attribution
    const string & id = elem.attr("id");

    Element e1;
    e1.name("link");
    e1.text("this is a link");
    e1.attr("href", "http://www.baidu.com");

    // append e1 to elem
    elem.append(e1);

    Element e2;
    e2.name("span");
    e2.text("this is a span");

    // append e2 to elem
    elem.append(e2);

    // serialize the elem to string 
    std::cout << elem.toString() << std::endl;

    return 0;
}