#include <boost/bind.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct demo
{
    int f(int a, int b)
    {
        return a + b;
    }
};

void test_case1(void)
{
    demo a, &ra = a;  //类实例对象和引用
    demo *p = &a;     //指针

    std::cout << bind(&demo::f, a, _1, 20)(10) << std::endl;
    std::cout << bind(&demo::f, ra, _2, _1)(10, 20) << std::endl;
    std::cout << bind(&demo::f, p, _1, _2)(10, 20) << std::endl;
}

struct point
{
    int x, y;
    point(int a = 0, int b = 0) : x(a), y(b) {}
    void print()
    {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
};

void test_case2()
{
    vector<point> v(10);
    //绑定成员函数
    for_each(v.begin(), v.end(), boost::bind(&point::print, _1));

    vector<int> v2(10);

    //绑定成员变量
    transform(v.begin(), v.end(), v2.begin(), boost::bind(&point::x, _1));

    for (auto x : v2) 
    {
        cout << x << ",";
    }
    cout << endl;
}

struct func 
{
    int operator ()(int a, int b) {
        return a + b;
    }
}; 

//函数对象
//如果函数对象内部没有定义result_type, 需要在绑定形式上做一点改动，用模板参数知名返回类型
void test_case3()
{
    cout << boost::bind<int>(func(), _1, _2) (1, 99) << endl;
    cout << boost::bind(std::greater<int>(), _1, _2)(99, 2) << endl;
}

int main()
{
    test_case1();
    test_case2();
    test_case3();
}