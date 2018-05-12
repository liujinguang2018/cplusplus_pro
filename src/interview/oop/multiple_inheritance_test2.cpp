#include <iostream>
using namespace std;

class Base
{
  public:
    virtual ~Base() {}
    virtual void DoNothing()
    {
        cout << "Base::DoNothing()" << endl;
    }

  private:
    unsigned int data;
};

class Base1 : virtual public Base
{
  public:
    virtual ~Base1() {}
    virtual void DoNothing()
    {
        cout << "Base1::DoNothing()" << endl;
    }
    virtual void DoNothing1() {}

  private:
    //unsigned int data;
};

class Base2 : virtual public Base
{
  public:
    virtual ~Base2() {}
    virtual void DoNothing()
    {
        cout << "Base2::DoNothing()" << endl;
    }
    virtual void DoNothing1() {}

  private:
    //unsigned int data;
};

class Derived : public Base1, public Base2
{
  public:
    Derived() : Base1(), Base2() {}
    virtual void DoNothing()
    {
        cout << "Derived::DoNothing()" << endl;
    }
    virtual void DoNothing2() {}

  private:
    unsigned int data;
    unsigned int data1;
};

int main()
{
    Derived d;

    cout << sizeof(d) << endl;

    Base1 &rbase1 = d;
    Base2 &rbase2 = d;

    rbase1.DoNothing();
    rbase2.DoNothing();
}
