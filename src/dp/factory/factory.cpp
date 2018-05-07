#include "factory.h"
#include "product.h"

#include <iostream>
using namespace std;


Factory::Factory()
{
    cout << "Factory() construtor" << endl;
}

Factory::~Factory()
{
    cout << "~Factory() destrutor" << endl;
}

ConcreteFactory::ConcreteFactory()
{
    cout << "ConcreteFactory() construtor" << endl;
}

ConcreteFactory::~ConcreteFactory()
{
    cout << "~ConcreteFactory() destrutor" << endl;
}

Product* ConcreteFactory::createProduct()
{
    return new ConcreteProduct();
}
