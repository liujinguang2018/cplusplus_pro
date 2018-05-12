#include "adapter_class.h"
#include <iostream>
using namespace std;

 Target::Target()
 {
     cout << "Target()" << endl;
 }

 Target::~Target()
 {
     cout << "~Target()" << endl;
 }

void Target::Request()
{
    cout << "Target::Request()" << endl;
}

Adaptee::Adaptee()
{
    cout << "Adaptee()" << endl;
}

Adaptee::~Adaptee()
{
    cout << "~Adaptee()" << endl;
}

void Adaptee::SpecificRequest()
{
    cout << "SpecificRequest()" << endl;
}


Adapter::Adapter()
{
    cout << "Adapter()" << endl;
}

Adapter::~Adapter()
{
    cout << "~Adapter()" << endl;
}

void Adapter::Request()
{
    cout << "Adapter::Request()" << endl;
    this->SpecificRequest();
}