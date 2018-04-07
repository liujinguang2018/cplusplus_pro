#include <thread>

using namespace std;

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

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    thread my_thread(my_func);

    my_thread.detach();
}

int main()
{
    oops();
}