#include "adapter_class.h"

int main()
{
    Target *adt = new Adapter();
    adt->Request();

    delete adt;
}