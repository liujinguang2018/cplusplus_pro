#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;
using namespace boost;

class abstract
{
  public:
    virtual void f();
    virtual void g();

  protected:
    virtual ~abstract() = default; //除了自己和子类，其他任何对象都无权调用delete来删除它
};

class impl : public abstract
{
  public:
    impl() = default;
    virtual ~impl() = default;
    virtual void f()
    {
        cout << "class impl f" << endl;
    }

    virtual void g()
    {
        cout << "class impl g" << endl;
    }
};

shared_ptr<abstract> create()
{
    return make_shared<impl>();
}

int main()
{
    auto p = create();

    p->f();
    p->g();
}