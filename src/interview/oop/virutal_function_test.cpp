#include <iostream>
using namespace std;

class Base
{
  public:
    virtual ~Base()
    {
        this->foo();
    }

    virtual void foo()
    {
        cout << "This is Base" << endl;
    }
};

class Derived : public Base {
    public:
        virtual ~Derived() {
            cout << "Derived Struct" << endl;
        }

        virtual void foo()
        {
            cout << "This is Derived" << endl;
        }
};

int main()
{
    Base *p = new Derived();
    p->foo();

    delete p;
}