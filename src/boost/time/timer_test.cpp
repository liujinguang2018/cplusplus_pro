#include <boost/timer.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
    timer t;

    //可度量的最大时间
    cout << "max time span: " << t.elapsed_max() / 3600 << "h" << endl;

    //boost::thread::sleep(boost::posix_time::seconds(5) + boost::get_system_time());
    boost::this_thread::sleep(boost::posix_time::seconds(2));

    //可度量的最小时间
    cout << "min time span: " << t.elapsed_min() << "S" << endl;

    //输出已经流逝的时间
    cout << "now time elapsed:" << t.elapsed() << "s" << endl;

    return 0;
}