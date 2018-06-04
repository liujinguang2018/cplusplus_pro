#include "builder.h"

#include <iostream>
using namespace std;

Builder::Builder()
{
    cout << "Builder()" << endl;
}

Builder::~Builder()
{
    cout << "~Builder()" << endl;
}

ConcreteBuilder::ConcreteBuilder()
{
    cout << "ConcreteBuilder()" << endl;
}

ConcreteBuilder::~ConcreteBuilder()
{
    cout << "~ConcreteBuilder()" << endl;
}

void ConcreteBuilder::buildPartA(const string &para)
{
    cout << "Step1:Build PartA..." << para << endl;
}

void ConcreteBuilder::buildPartB(const string &para)
{
    cout << "Step1:Build PartB..." << para << endl;
}

void ConcreteBuilder::buildPartC(const string &para)
{
    cout << "Step1:Build PartC..." << para << endl;
}

Product *ConcreteBuilder::getProduct()
{
    buildPartA("pre-defined");
    buildPartB("pre-defined");
    buildPartC("pre-defined");

    return new Product();
}

