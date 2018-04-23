#include <iostream>
#include <string.h>
using namespace std;

//有3种情况，会以一个object的内容作为另外一个class object的初值
//1. 明确地以一个ojbect的内容作为另外一个class object的初值
//2. 当object作为参数交给某个函数时
//3. 函数返回一个class object对象

//default constructors和copy constructors在必要的时候采用编译器产生出来

//如果class没有提供一个explicit copy constructor又当如何？ 当class object
//以“相同class的另外一个object”作为初值时，其内部是以所谓的default
//memberwise initialization手法完成的，也就是每一个内建或派生的data member
//的值，从一个object拷贝到另外一个object身上。不过它并不会拷贝其中的
//member class ojbect, 而是以递归的方式施行memberwise initialization

//什么时候一个class不展现出"bitwise copy semantics"呢？有4种情况
//1. 当class内含一个member object而后者的class声明一个copy constructor时
//2. 当class继承自一个base class而后者存在有一个copy constructor时
//这两种情况编译器必须将member或base class的copy constructor调用安插
//到被合成的copy constructor中
//3. 当class声明了一个或多个virtual functions时(处理vptr)
//4. 当class派生自一个继承串链，其中有一个或者多个virtual base class时
//在这四种情况下，如果缺乏一个已声明的copy constructor,
//编译器为了正确处理"以一个class object作为另外一个class object的初值",
//必须合成出一个copy constructor

//class test;

//test foo(double)

class test
{
    friend test foo(double);

  public:
    test()
    {
        memset(array, 0, sizeof(double) * SIZE);
    }

    inline test(const test &t) {
        memcpy(this, &t, sizeof(test));
    }

  private:
    constexpr static int SIZE = 100;
    double array[SIZE];
    //constexpr static int SIZE = 100;
};

test foo(double val)
{
    test local;

    local.array[0] = val;
    local.array[99] = val;

    return local;
}

int main()
{
    for (int cnt = 0; cnt < 10000000; ++cnt) {
        test t = foo(cnt);
    }
}