#include <boost/timer.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
    timer t;

    //�ɶ��������ʱ��
    cout << "max time span: " << t.elapsed_max() / 3600 << "h" << endl;

    //boost::thread::sleep(boost::posix_time::seconds(5) + boost::get_system_time());
    boost::this_thread::sleep(boost::posix_time::seconds(2));

    //�ɶ�������Сʱ��
    cout << "min time span: " << t.elapsed_min() << "S" << endl;

    //����Ѿ����ŵ�ʱ��
    cout << "now time elapsed:" << t.elapsed() << "s" << endl;

    return 0;
}