#include <boost/thread/xtime.hpp>
#include <boost/thread/thread_only.hpp>
#include <iostream>

struct thread_alarm
{
    thread_alarm(int secs) : m_secs(secs)
    {
    }

    void operator()() {
        boost::xtime xt;
        boost::xtime_get(&xt, boost::TIME_UTC_);
        xt.sec += m_secs;

        std::cout << "sleep " << m_secs << " seconds..." << std::endl;
        boost::thread::sleep(xt);
        std::cout << "alarm sounded..." << std::endl;
    }
    int m_secs;
};

int main()
{
    int secs = 5;

    std::cout << "setting alarm for " << secs << " seconds" << std::endl;
    thread_alarm alarm(secs);
    boost::thread thrd(alarm);
    thrd.join();
}