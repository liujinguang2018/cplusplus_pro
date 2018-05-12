#include <iostream>
using namespace std;

class Base
{
  public:
    virtual void DoNothing() const
    {
        cout << "Base::DoNothing()" << endl;
    }
    virtual void DoNothing1()
    {
        cout << "Base::DoNothing1()" << endl;
    }

  private:
    unsigned int data;
};

class Derived : public Base
{
  public:
    virtual void DoNothing() const override
    {
        cout << "Derived::DoNothing()" << endl;
    }
    virtual void DoNothing2()
    {
        cout << "Derived::DoNothing2()" << endl;
    }

  private:
    unsigned int data;
    unsigned int data1;
};

void doSomething1(const Base& obj)
{
    obj.DoNothing();
}

void doSomething2(Base obj)
{
    obj.DoNothing();
}

int main(int argc, char *argv[])
{
    typedef void (Base::*PFN) () const;
    PFN pfn = &Base::DoNothing;

    Derived d;
    Base &rbase = d;
    Base *pbase = &d;

    d.DoNothing();
    rbase.DoNothing();
    pbase->DoNothing();
    ((*pbase).*pfn)();
    (pbase->*pfn)();
    (d.*pfn)();
    (&d->*pfn)();

    cout << "===============" << endl;
    doSomething1(d);
    doSomething2(d);
}
