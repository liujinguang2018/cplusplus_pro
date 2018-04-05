#include <functional>
#include <iostream>
#include <boost/bind.hpp>

//高级主题
int f(int a, int b)
{
    return a + b;
}

//为占位符更名
int main()
{
    const boost::arg<1> &_x = boost::placeholders::_1;
    const boost::arg<2> &_y = boost::placeholders::_2;

    std::cout << boost::bind(f, _x, _y)(10, 20) << std::endl;

    auto &arg1 = boost::placeholders::_1;
    decltype(boost::placeholders::_2)& arg2 = boost::placeholders::_2;

    std::cout << boost::bind(f, arg1, arg2)(10, 30) << std::endl;


    //存储bind表达式
    auto x = boost::bind(f, _1, _2);
    std::cout << x(1,2) << std::endl;
}