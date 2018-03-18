#include <boost/thread/thread.hpp>
#include <boost/timer.hpp>
#include <iostream>

void hello()
{
    while (1)
    {
        std::cout << "Hello world, I'm a thread!" << std::endl;
        boost::this_thread::sleep(boost::posix_time::seconds(2));
    }
}

int main(int argc, const char *argv[])
{
    boost::thread thrd(&hello);
    thrd.join();

    return 0;
}