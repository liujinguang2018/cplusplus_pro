#include <thread>
#include <iostream>

using namespace std;

void do_something()
{
    cout << "do something" << endl;
}

void do_something_else()
{
    cout << "do something else" << endl;
}

class background_task
{
  public:
    void operator()() const
    {
        do_something();
        do_something_else();
    }
};

int main()
{
    //background_task bt;
    //thread t(bt);

    //这里相当与声明了一个名为my_thread的函数，这个函数带有一个参数(函数指针指向没有参
    //数并返回background_task对象的函数)，返回一个 std::thread 对象的函数，而非启动了一个
    //线程。
    //thread t(background_task());

    //使用在前面命名函数对象的方式，或使用多组括号①，或使用新统一的初始化语法②，可以避
    //免这个问题。
    //thread t((background_task()));
    //thread t{background_task()};

    //lamda表达式形式
    thread t([]{
        do_something();
        do_something_else();
    });

    t.join();

    cout << thread::hardware_concurrency() << endl;
}