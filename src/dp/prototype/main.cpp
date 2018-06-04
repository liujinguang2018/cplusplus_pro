#include "prototype.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Prototype *p = new ConcretePrototype();
    Prototype *p1 = p->clone();

    delete p1;
    delete p;
}