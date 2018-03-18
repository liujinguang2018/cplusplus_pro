
#include <boost/thread/thread_only.hpp>
#include <boost/thread/xtime.hpp>
#include <iostream>

using namespace std;

int main()
{
    boost::xtime xt;
    boost::xtime_get(&xt, boost::TIME_UTC_);

    xt.sec += 2;

    boost::thread::sleep(xt);
}