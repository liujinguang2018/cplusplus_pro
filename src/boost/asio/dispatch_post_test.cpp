#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <iostream>

boost::mutex global_stream_lock;

void WorkThread(boost::shared_ptr<boost::asio::io_service> io_service)
{
    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id() << "] Thread Start" << std::endl;
    global_stream_lock.unlock();

    io_service->run();

    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id() << "] Thread Finish" << std::endl;
    global_stream_lock.unlock();
}

int main()
{

}