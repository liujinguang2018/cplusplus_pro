#include "adapter_object.h"
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


Adapter::Adapter(Adaptee *adaptee)
{
    cout << "Adapter()" << endl;
    adaptee_ = adaptee;
}

Adapter::~Adapter()
{
    cout << "~Adapter()" << endl;
    delete adaptee_;
}

void Adapter::Request()
{
    cout << "Adapter::Request()" << endl;
    adaptee_->SpecificRequest();
}