# yazi-xml
a tiny c++ xml library.

|Author|junping|
|---|---|
|E-mail|oldjun@sina.com|
|Wechat|chenjunping1024|

## Redefine the format of XML document

yazi-xml doesn't support the whole XML standard, because this reason I simplify the XML form.

### The well form of XML document
```xml
<?xml version="1.0"?>
<students>
    <!-- this is comment -->
    <student id="1" class="101">
        <name>Jack</name>
        <age>23</age>
        <gender>man</gender>
    </student>
    <student id="2" class="102">
        <name>Lucy</name>
        <age>21</age>
        <gender>girl</gender>
    </student>
    <student id="3" class="103">
        <name>Lily</name>
        <age>22</age>
        <gender>girl</gender>
    </student>
</students>
```

### The bad form of XML document
```xml
<?xml version="1.0"?>
<students>
    this is a confused text
    <student id="1" class="101">
        <name>Jack</name>
        <age>23</age>
        <gender>man</gender>
    </student>
</students>
```
> Tips: Each well form XML document should only has one root element, an element should either contains text or child element.

## Parsing string to XML ducoment
```c++
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
    
    return 0;
}
```

## Loop over the XML element
```c++
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

    // find the first child element of root, and which's name is equals to student
    const Element & student = root["student"];

    // loop over student's child element
    for (Element::const_iterator it = student.begin(); it != student.end(); it++)
    {
        std::cout << (*it).toString() << std::endl;
    }
    
    return 0;
}
```

## Manipulate the XML element
```c++
#include "Document.h"
#include "Element.h"
using namespace yazi::xml;

int main()
{
    // create a xml element
    Element elem;

    // set the elem's name
    elem.name("root");

    // set the elem's attribution
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
```
## Compile & Run the project
download the source code, cd into the yazi-xml project working directory, run command make && ./main 
```bash
cd ./yazi-xml
make
./main
```


