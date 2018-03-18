//使用mutex实现一个原子操作的计数器basic_atom，可以安全在多线程环境下正确计数

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/noncopyable.hpp>
#include <iostream>

template <typename T>
class basic_atom : boost::noncopyable
{
  private:
    T n;

    //typedef mutex mutex_t;
    boost::mutex mu;

  public:
    basic_atom(T x = T()) : n(x) {}
    T operator++() //前置式递增操作符
    {
        boost::unique_lock<boost::mutex> lock(mu);
        return ++n;
    }

    operator T() { return n; } //类型转换操作符定义
};

boost::mutex io_mutex; // the iostream are not guaranteed to be thread-safe
basic_atom<int> count(0);

void change_count()
{
    //++count;
    //boost::unique_lock<boost::mutex> scoped_lock(io_mutex);
    boost::mutex::scoped_lock scoped_lock(io_mutex);
    std::cout << "count = " << ++count << std::endl;
}

int main()
{
    const int num_threads = 4000;
    boost::thread_group thrds;
    for (int i = 0; i < num_threads; ++i)
    {
        thrds.create_thread(&change_count); //当成功创建了一个thread对象后，线程立刻开始执行，thread不提供start(), begin()
    }

    thrds.join_all();

    return 0;
}