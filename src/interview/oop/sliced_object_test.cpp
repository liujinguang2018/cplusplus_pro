#include <iostream>
using namespace std;

class Base
{
  public:
    Base()
    {
        b = 0;
    }
    virtual void DoNothing()
    {
        cout << "Base::DoNothing(); b=" << b << endl;
    }

  private:
    unsigned int b;
};

class Derived : public Base
{
  public:
    Derived()
    {
        d = 1;
    }
    virtual void DoNothing()
    {
        cout << "Derived::DoNothing(); d=" << d << endl;
    }

  private:
    unsigned int d;
};

void DoSomething1(Base barr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        barr[0].DoNothing();
    }
}

int main()
{
    Derived dv[4];
    DoSomething1(dv, sizeof(dv) / sizeof(dv[0]));
}
