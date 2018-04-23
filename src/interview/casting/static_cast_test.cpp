#include <iostream>

using namespace std;

class Widget
{
  public:
    //explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的
    explicit Widget(int size) : size_(size)
    {
        cout << "constructor" << endl;
    }

    int get_size() const
    {
        return size_;
    }

  private:
    int size_;
};

void doSomeWork(const Widget &w)
{
    cout << "size = " << w.get_size() << endl;
}

int main()
{
    doSomeWork(Widget(15));
    //doSomeWork(15);
    doSomeWork(static_cast<Widget>(15));
}