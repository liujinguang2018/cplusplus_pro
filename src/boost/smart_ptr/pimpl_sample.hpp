#ifndef PIMPL_SAMPLE
#define PIMPL_SAMPLE

#include <boost/smart_ptr.hpp>
//
// pimpl惯用法的思路是把客户和类的私有部分内容相隔离。因为客户依赖于类的头文件，为避免
// 头文件中变化影响到客户，pimpl的惯用法是通过将私有数据和函数放入到定义在实现文件的
// 一个单独类型中，让后在头文件中对这个类型进行前置声明，并保存一个指向该类型的指针，
// 隐藏相关细节内容。
//桥接(bridge pattern)模式应用: 它可以改变具体的实现而外界对此一无所知，同时也减少了
//源文件之间的编译依赖，是程序获得了更多的灵活性。
//本例引用参加shared_ptr_advanced_test.cpp
//

class pimpl_sample
{
  private:
    class impl;   ///不完整的内部类声明
    //impl *pimpl_;
    boost::shared_ptr<impl> pimpl_;

  public:
    pimpl_sample(std::string s);
    ~pimpl_sample();
    void do_something();
};

#endif