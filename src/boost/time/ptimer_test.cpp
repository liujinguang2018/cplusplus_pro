#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace std;
using namespace boost::posix_time;

template <typename Clock = microsec_clock>
class basic_ptimer
{
  public:
    basic_ptimer()
    {
        restart();
    }

    void elapsed() const
    {
        cout << Clock::local_time() - start_time_ << endl;
    }

    void restart()
    {
        start_time_ = Clock::local_time();
    }
    ~basic_ptimer()
    {
        elapsed();
    }

  private:
    ptime start_time_;
};

typedef basic_ptimer<microsec_clock> ptimer;
typedef basic_ptimer<second_clock> sptimer;

int main()
{
    ptimer t;
}