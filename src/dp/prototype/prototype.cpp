#include "prototype.h"

#include <iostream>
using namespace std;

Prototype::Prototype()
{
}

Prototype::~Prototype()
{
}

Prototype *Prototype::clone() const
{
    return 0;
}

ConcretePrototype::ConcretePrototype()
{
}

ConcretePrototype::~ConcretePrototype()
{
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
{
    cout << "ConcretePrototype copy..." << endl;
}

Prototype* ConcretePrototype::clone() const 
{
    return new ConcretePrototype(*this);
}