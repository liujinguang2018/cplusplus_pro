#include <iostream>
using namespace std;

class Base
{
  public:
    virtual void foo()
    {
        cout << "Base::foo()" << endl;
    }

    virtual void foo(int i)
    {
        cout << "Base::foo(" << i << ")" << endl;
    }
};

class Derived : public Base
{
  public:
    virtual void foo()
    {
        cout << "Derived::foo()" << endl;
    }
};

int main()
{
    Derived one_derive;
    one_derive.foo();

    Base *pbase = new Derived();
    pbase->foo(1);
}