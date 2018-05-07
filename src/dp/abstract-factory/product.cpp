#include "product.h"

#include <iostream>
using namespace std;


AbstractProductA::AbstractProductA()
{
    cout << "AbstractProductA()" << endl;
}

AbstractProductA::~AbstractProductA()
{
    cout << "~AbstractProductA()" << endl;
}

ProductA1::ProductA1()
{
    cout << "ProductA1()" << endl;
}

ProductA1::~ProductA1()
{
    cout << "~ProductA1()" << endl;
}

ProductA2::ProductA2()
{
    cout << "ProductA2()" << endl;
}

ProductA2::~ProductA2()
{
    cout << "~ProductA2()" << endl;
}

AbstractProductB::AbstractProductB()
{
    cout << "AbstractProductB()" << endl;
}

AbstractProductB::~AbstractProductB()
{
    cout << "~AbstractProductB()" << endl;
}

ProductB1::ProductB1()
{
    cout << "ProductB1()" << endl;
}

ProductB1::~ProductB1()
{
    cout << "~ProductB1()" << endl;
}

ProductB2::ProductB2()
{
    cout << "ProductB2()" << endl;
}

ProductB2::~ProductB2()
{
    cout << "~ProductB2()" << endl;
}
