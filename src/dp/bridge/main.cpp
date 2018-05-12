#include "abstraction_imp.h"
#include "abstraction.h"

#include <iostream>
using namespace std;

int main()
{
    AbstractionImp *imp = new ConcreteAbstractionImpA();
    Abstraction *abs = new RefinedAbstraction(imp);

    abs->operation();

    cout << endl;

    delete abs;
    delete imp;
}
