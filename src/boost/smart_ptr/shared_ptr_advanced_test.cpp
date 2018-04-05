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

/////////////////////////////测试删除器
void test_deleter()
{
    boost::shared_ptr<FILE> fp(fopen("./CMakeLists.txt", "r"), fclose);
}

////////////////////////////显示bool转型
//处于兼容性考虑，C++11标准规定在if/assert/for等逻辑判断的语境
//下shared_ptr还是可以“隐式”的，但是其他情形---如函数参数和返回值
//--则必须显示转换
bool test_bool()
{
    auto p = boost::make_shared<int>(176);

    assert(p);

    if (p)
    {
        std::cout << "explicit cast" << std::endl;
    }

    //return static_cast<bool>(p);
    return p != nullptr;
}

//测试指针转型函数
void test_cast()
{
    boost::shared_ptr<std::exception> sp1(new std::bad_exception());
    auto sp2 = boost::dynamic_pointer_cast<std::bad_exception>(sp1);
    auto sp3 = boost::static_pointer_cast<std::exception>(sp2);

    assert(sp1 == sp3);
}

void any_func()
{
    std::cout << "any func" << std::endl;
}

int main()
{
    std::cout << "=====test make_shared factory method=====" << std::endl;
    test_factory_method();

    std::cout << "=====test container method=====" << std::endl;
    test_container_app();    

    std::cout << "=====test bridge pattern application=====" << std::endl;
    test_bridge_app();

    //shared_ptr<void>存储了一个空指针，并指定了删除器是操作void *的一个函数,
    //因而当它析构时会自动调用函数any_func(),从而执行任意我们想做的工作
    boost::shared_ptr<void>(nullptr, any_func);
}