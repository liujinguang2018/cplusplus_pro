#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <string>
#include <map>

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;


class work_time
{
  public:
    typedef map<time_period, string> map_t;
    work_time() 
    {
        init();
    }

    void greeting(const ptime &t) const 
    {
        for (auto &x:map_ts) {
            if (x.first.contains(t)) {
                cout << x.second << endl;
                break;
            }
        }
    }

  private:
    map_t map_ts;
    void init()
    {
        ptime p(day_clock::local_day());

        map_ts[time_period(p, hours(9))] = "It's too early, just relax.\n";

        p += hours(9);
        map_ts[time_period(p, hours(3) + minutes(30))] = "It's AM, please work hard.\n";

        p += hours(3) + minutes(30);
        map_ts[time_period(p, hours(1))] = "It's lunch time, are you hungry?\n";

        p += hours(1);
        map_ts[time_period(p, hours(4) + minutes(30))] = "It's PM, ready to go home.\n";

        p += hours(4) + minutes(30);
        map_ts[time_period(p, hours(6))] = "Are you still working? you do need a rest.\n";
    }
};

int main()
{
    work_time wt;
    wt.greeting(second_clock::local_time());
}