#include <boost/progress.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <string>

using namespace std;


int main()
{
    const int count = 100;
    boost::progress_display pd(count);

    for (int i = 0; i < 100; i++) {
        boost::this_thread::sleep(boost::posix_time::seconds(1));
        ++pd;
    }

    return 0;
}