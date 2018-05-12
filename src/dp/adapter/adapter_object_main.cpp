#include "adapter_object.h"

int main()
{
    //Adaptee *adaptee = new Adaptee();
    Target *adt = new Adapter(new Adaptee());
    adt->Request();

    delete adt;
}