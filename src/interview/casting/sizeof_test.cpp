#include <iostream>

using namespace std;

struct test01
{
};

class test02
{
    test02() = default;
    ~test02() = default;
};

class test03
{
    test03() = default;
    ~test03() = default;
    virtual void func1() = 0;
    virtual void func2() = 0;
};

int main()
{
    cout << "sizeof struct test01 = " << sizeof(test01) << endl; ///取决于编译器，gcc为1
    cout << "sizeof class test02 = " << sizeof(test02) << endl;
    //C++编译器一旦发现一个类型中有虚函数，就会为该类型生成虚函数表，
    //并在该类型的每一个实例中添加一个指向虚函数的指针.
    //sizeof大小取决于机器位数，32bit机器4字节，64bit机器为8字节
    cout << "sizeof virtual class test03 = " << sizeof(test03) << endl;
}