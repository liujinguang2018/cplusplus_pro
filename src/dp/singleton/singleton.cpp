#include "singleton.h"

#include <iostream>
using namespace std;

Singleton *Singleton::instance_;
Singleton::GC Singleton::gc;

Singleton::Singleton(int value)
{
    value_ = value;
    cout << "Signleton()" << endl;
}

Singleton::~Singleton()
{
    cout << "~Signleton()" << endl;
}

Singleton *Singleton::instance()
{
    if (instance_ == nullptr)
    {
        instance_ = new Singleton(10);
    }

    return instance_;
}
