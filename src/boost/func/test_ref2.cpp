#include <boost/ref.hpp>
#include <iostream>

using namespace std;

class big_class
{
  private:
    int x;

  public:
    big_class() : x(0) {}
    void print()
    {
        cout << "big_class " << ++x << endl;
    }
};

template<typename T>
void print(T t)
{
    for (int i = 0; i < 2; i++)
    {
        boost::unwrap_ref(t).print();
    }
}

int main()
{
    big_class c;
    auto rw = boost::ref(c);
    c.print();

    print(c);    ///拷贝参数，内部状态不改变
    print(rw);   //引用参数，内部状态改变
    print(c);

}