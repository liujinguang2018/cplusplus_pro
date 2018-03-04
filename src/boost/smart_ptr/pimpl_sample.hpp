#ifndef PIMPL_SAMPLE
#define PIMPL_SAMPLE
//
// pimpl惯用法的思路是把客户和类的私有部分内容相隔离。因为客户依赖于类的头文件，为避免
// 头文件中变化影响到客户，pimpl的惯用法是通过将私有数据和函数放入到定义在实现文件的
// 一个单独类型中，让后在头文件中对这个类型进行前置声明，并保存一个指向该类型的指针，
// 隐藏相关细节内容。
//

struct impl;

class pimpl_sample {
    impl * pimpl_;
    //boost::scoped_ptr<impl> pimpl_;

    public:
    pimpl_sample();
    ~pimpl_sample();
    void do_something();
};

#endif