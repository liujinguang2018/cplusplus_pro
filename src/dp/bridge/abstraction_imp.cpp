#include "abstraction_imp.h"

#include <iostream>
using namespace std;

AbstractionImp::AbstractionImp()
{
    cout << "AbstractionImp()" << endl;
}

AbstractionImp::~AbstractionImp()
{
    cout << "~AbstractionImp()" << endl;
}

void AbstractionImp::operation()
{
    cout << "AbstractionImp::operation()" << endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA()
{
    cout << "ConcreteAbstractionImpA()" << endl;
}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA()
{
    cout << "~ConcreteAbstractionImpA()" << endl;
}

void ConcreteAbstractionImpA::operation()
{
    cout << "ConcreteAbstractionImpA::operation()" << endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB()
{
    cout << "ConcreteAbstractionImpB()" << endl;
}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB()
{
    cout << "~ConcreteAbstractionImpB()" << endl;
}

void ConcreteAbstractionImpB::operation()
{
    cout << "ConcreteAbstractionImpB::operation()" << endl;
}
