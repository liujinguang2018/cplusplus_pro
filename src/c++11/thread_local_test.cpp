#include <thread>
#include <iostream>

using namespace std;

//线程本地存储是多线程编程里的概念，是指变量在进程里拥有不止一个实例，
//每个线程都会拥有一个完全独立的、“线程本地化”的拷贝，多个线程对变量的
//读写互不干扰，完全避免了竞争、同步问题

static int y = 0;
thread_local int z = 0;  ///线程局部存储，每个线程都与都拥有独立实体

auto f = [&]() {
    ++y, ++z;
    cout << "y=" << y <<",z=" << z << endl;
};

int main()
{
    thread t1(f);
    thread t2(f);
    t1.join();
    t2.join();

    cout << "y=" << y <<",z=" << z << endl;
}