#include "abstraction.h"
#include "abstraction_imp.h"

#include <iostream>
using namespace std;

Abstraction::Abstraction()
{
    cout << "Abstraction()" << endl;
}

Abstraction::~Abstraction()
{
    cout << "~Abstraction()" << endl;
}

RefinedAbstraction::RefinedAbstraction(AbstractionImp *imp)
{
    cout << "RefinedAbstraction(AbstractionImp *imp)" << endl;
    imp_ = imp;
}

RefinedAbstraction::~RefinedAbstraction()
{
    cout << "~RefinedAbstraction()" << endl;
}

void RefinedAbstraction::operation()
{
    imp_->operation();
}

