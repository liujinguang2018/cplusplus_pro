#include "director.h"

int main(int argc, char *argv[])
{
    Director *d = new Director(new ConcreteBuilder());

    d->construct();

    delete d;
}