#include <vector>
#include <string>
#include <iostream>
#include <boost/smart_ptr.hpp>

#include "pimpl_sample.hpp"

////////////////////////////验证工厂函数
void test_factory_method()
{
    auto sp = boost::make_shared<std::string>("make_shared");
    std::cout << *sp << std::endl;

    auto spv = boost::make_shared<std::vector<int> >(10,2);
    std::cout << (*spv)[0] << std::endl;
}

////////////////////////////应用于容器
void test_container_app()
{
    std::vector<boost::shared_ptr<int> > vs(10);   ///声明有10个元素的容器, 元素均为空指针

    int i = 0;
    for (auto pos = vs.begin(); pos != vs.end(); ++pos)
    {
        (*pos) = boost::make_shared<int>(++i);
    }

    //C++11的for循环，引用形式，避免迭代器到shared_ptr的两次引用
    for (auto& ptr: vs) {
        std::cout << *ptr << ", ";
    }
    std::cout << std::endl;
}

/////////////////////////////测试桥接模式
void test_bridge_app()
{
    pimpl_sample sample("Just test");
    sample.do_something();
}

int main()
{
    std::cout << "=====test make_shared factory method=====" << std::endl;
    test_factory_method();

    std::cout << "=====test container method=====" << std::endl;
    test_container_app();    

    std::cout << "=====test bridge pattern application=====" << std::endl;
    test_bridge_app();
}