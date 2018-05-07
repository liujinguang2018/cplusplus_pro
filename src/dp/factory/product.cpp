#include "product.h"
#include <iostream>

using namespace std;

Product::Product()
{
    cout << "Product() constructor." << endl;
}

Product::~Product()
{
    cout << "Product() destructor." << endl;
}

ConcreteProduct::ConcreteProduct()
{
    cout << "ConcreteProduct() constructor." << endl;
}

ConcreteProduct::~ConcreteProduct()
{
    cout << "ConcreteProduct() destructor." << endl;
}