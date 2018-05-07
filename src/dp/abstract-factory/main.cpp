#include "product.h"
#include "factory.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    AbstractFactory* af1 = new ConcreteFactory1();
    AbstractProductA* apa1 = af1->createProductA();
    AbstractProductB* apb1 = af1->createProductB();
    cout << endl;

    AbstractFactory* af2 = new ConcreteFactory2();
    AbstractProductA* apa2 = af2->createProductA();
    AbstractProductB* apb2 = af2->createProductB();
    cout << endl;

    delete apb2;
    delete apa2;
    delete af2;
    cout << endl;

    delete apb1;
    delete apa1;
    delete af1;
}