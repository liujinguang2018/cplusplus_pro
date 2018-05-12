#include "decorator.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Decorator *dec = new ConcreteDecorator(new ConcreteComponent());
    dec->operation();

    delete dec;
}