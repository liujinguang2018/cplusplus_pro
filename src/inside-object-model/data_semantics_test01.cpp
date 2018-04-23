#include <iostream>

using namespace std;

class X {};
class Y : public virtual X {};
class Z : public virtual X {};

class A : public Y, public Z {};
//编译器自动加上的额外data members，用以支持某些语言特性(主要是各种virtual特性)
int main()
{
    cout << "sizeof(X) = " << sizeof(X) << endl;
    cout << "sizeof(Y) = " << sizeof(Y) << endl;
    cout << "sizeof(Z) = " << sizeof(Z) << endl;
    cout << "sizeof(A) = " << sizeof(A) << endl;
}