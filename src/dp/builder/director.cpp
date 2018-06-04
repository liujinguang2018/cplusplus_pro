#include "director.h"

#include <iostream>
using namespace std;

Director::Director(Builder *bld)
{
    _bld = bld;
}

Director::~Director()
{
    delete _bld;
}

void Director::construct()
{
    _bld->buildPartA("user-defined");
    _bld->buildPartB("user-defined");
    _bld->buildPartC("user-defined");
}