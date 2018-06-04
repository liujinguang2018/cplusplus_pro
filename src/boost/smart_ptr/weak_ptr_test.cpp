#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/enable_shared_from_this.hpp>
#include <iostream>
//using namespace std;

using namespace boost;

class Shared : public enable_shared_from_this< Shared >
{
  public:
    Shared(int n) : x(n) {}
    int x;
    void print()
    {
        std::cout << "shared " << x << std::endl;
    }
};

void enable_shared_from_this_test()
{
    auto sp = make_shared<Shared>(313);
    sp->print();

    auto p = sp->shared_from_this();

    p->x = 1000;
    p->print();
}

void basic_weak_ptr_test()
{
    shared_ptr<int> sp(new int(10));
    assert(sp.use_count() == 1);

    weak_ptr<int> wp(sp);
    assert(wp.use_count() == 1);

    if (!wp.expired())
    {
        shared_ptr<int> sp2 = wp.lock();
        *sp2 = 100;

        assert(wp.use_count() == 2);
    } //退出作用域，sp2自动析构，引用计数减1

    assert(wp.use_count() == 1);
    sp.reset();

    assert(wp.expired());
    assert(!wp.lock()); //weak_ptr将获取一个空指针
}

int
main(int argc, char *argv[])
{
    basic_weak_ptr_test();
    enable_shared_from_this_test();
}
