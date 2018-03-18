#include <boost/progress.hpp>
#include <boost/thread.hpp>
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    {
        boost::progress_timer t;

        boost::this_thread::sleep(boost::posix_time::seconds(3));
    }

    stringstream ss; //字符串流对象
    {
        boost::progress_timer t(ss);
        boost::this_thread::sleep(boost::posix_time::seconds(3));
    }
    cout << ss.str() << endl;

    return 0;
}