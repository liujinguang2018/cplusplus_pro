#include <boost/bind.hpp>
#include <iostream>

int f(int a, int b)
{
    return a + b;
}

int g(int a, int b, int c)
{
    return a + b * c;
}

typedef decltype(&f) f_type;   ///函数指针的定义
typedef decltype(&g) g_type;

f_type pf = f;
g_type pg = g;

int main()
{
    std::cout << boost::bind(f, 1, 2)() << std::endl; 
    std::cout << boost::bind(f, _1, 9)(2) << std::endl; ///支持占位符设置
    std::cout << boost::bind(g, 1, 2, 3)() << std::endl;

    int x = 1, y = 2, z = 3;

    std::cout << boost::bind(pf, _1, 9)(x) << std::endl;
    std::cout << boost::bind(pg, _3, _2, _2)(x, y, z) << std::endl;
}