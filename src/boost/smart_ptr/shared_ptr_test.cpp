#include <boost/shared_ptr.hpp>
#include <cassert>
#include <iostream>
#include <assert.h>

class Shared
{
    boost::shared_ptr<int> no_;

  public:
    Shared(boost::shared_ptr<int> no) : no_(no) {}

    void set(int i)
    {
        *no_ = i;
    }

    int get()
    {
        return *no_;
    }

    void print()
    {
        std::cout << "count: " << no_.use_count() << ", value=" << *no_ << std::endl;
    }
};

void print_func(boost::shared_ptr<int> p)
{
    std::cout << "count: " << p.use_count() << ", value=" << *p << std::endl;
}

int main()
{
    boost::shared_ptr<int> temp(new int(4));
    Shared a(temp);
    Shared b(temp);

    a.print();
    assert(temp.use_count() == 3);

    std::cout << b.get() << std::endl;
    assert(b.get() == 4);

    a.set(28);
    assert(b.get() == 28);
    b.print();
    print_func(temp);
    b.print();

    return 0;
}