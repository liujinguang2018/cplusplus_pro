#include <iostream>

using namespace std;

class Base {
    public:
        virtual double f1(double) noexcept;         //不会抛出异常
        virtual int f2() noexcept(false);  //
        virtual void f3();
};

class Derived : Base {
    public:
        double f1(double d) {
            cout << d << endl;
        }

        int f2() noexcept(true) {
            return 0;
        }

        void f3() noexcept {

        }

};

int main() {
    Derived d;
    d.f1(2);

    return 0;
}