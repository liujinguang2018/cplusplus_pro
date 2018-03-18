//当成功创建了一个thread对象后，线程立刻开始执行，thread不提供start(), begin()
//本例展示如何如何向thread对象传递参数

#include <boost/detail/atomic_count.hpp>
#include <boost/thread/thread.hpp>
#include <boost/ref.hpp>
#include <iostream>

boost::mutex io_mutex;
boost::detail::atomic_count count(0);

void printing(boost::detail::atomic_count &count, const std::string &str)
{
    for (int i = 0; i < 1000; ++i)
    {
        boost::mutex::scoped_lock lock(io_mutex);
        std::cout << str << " " << ++count << std::endl;
        std::cout << boost::this_thread::get_id() << std::endl;
    }
}

int main()
{
    std::cout << boost::thread::hardware_concurrency() << std::endl;

    //boost::detail::atomic_count count(0);

    //使用临时对象启动线程
    // boost::thread::thread(boost::bind(printing, boost::ref(count), "hello"));
    // boost::thread::thread(boost::bind(printing, boost::ref(count), "boost"));

    try
    {
        boost::thread t1(printing, boost::ref(count), "hello");
        boost::thread t2(printing, boost::ref(count), "boost");

        t1.join();
        t2.join();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //boost::this_thread::sleep(boost::posix_time::seconds(5));
}