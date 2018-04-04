#include "pimpl_sample.hpp"
#include <string>
#include <iostream>

class pimpl_sample::impl
{
  public:
    impl(std::string s) : s_(s) {}
    void do_something()
    {
        std::cout << s_ << std::endl;
    }

  private:
    std::string s_;
};

//pimpl_sample类的构造函数在构造了pimpl之后可能会抛出一个异常
//在构造函数中抛出异常意味着构造对象并没有真正存在，因此在栈展开
//时，将不会调用它的够着函数。这就说明有impl_指针分配并引起的内存
//将会泄露
pimpl_sample::pimpl_sample(std::string s) : pimpl_(new impl(s))
{
}

pimpl_sample::~pimpl_sample()
{
}

void pimpl_sample::do_something()
{
    pimpl_->do_something();
}