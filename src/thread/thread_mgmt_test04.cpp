#include <thread>
#include <iostream>

using namespace std;

//如需确保线程在函数之前
//结束——查看是否因为线程函数使用了局部变量的引用，以及其他原因——而后再确定一下
//程序可能会退出的途径，无论正常与否，可以提供一个简洁的机制，来做解决这个问题。
//一种方式是使用“资源获取即初始化方式”(RAII，Resource Acquisition Is Initialization)，并且
//提供一个类，在析构函数中使用join()，

class thread_guard
{
    thread & t;

    public:
        thread_guard(thread &t_) : t(t_) {}
        ~thread_guard() {
            if (t.joinable()) {
                t.join();

                cout << "thread " << t.get_id() << "is joined" << endl;
            }
        }

        thread_guard(thread_guard const &) = delete;
        thread_guard& operator=(thread_guard const &) = delete;
};

//如果不等待线程，就必须保证线程结束之前，可访问的数据得有效性。
//这种情况很可能发生在线程还没结束，函数已经退出的时候，这时线程函数还持有函数局部
//变量的指针或引用。
void do_somthing(int &i)
{
    ++i;
}

struct func
{
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (int i = 0; i < 10000000; i++)
        {
            do_somthing(i);
        }
    }
};

void do_somthing_in_concurrent_thread()
{
}

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    thread my_thread(my_func);

    thread_guard g(my_thread);

    do_somthing_in_concurrent_thread();
    //当线程执行到④处时，局部对象就要被逆序销毁了。因此，thread_guard对象g是第一个被销
    //毁的，这时线程在析构函数中被加入②到原始线程中。即
    //使do_something_in_current_thread抛出一个异常，这个销毁依旧会发生。
}

int main()
{
    oops();
}