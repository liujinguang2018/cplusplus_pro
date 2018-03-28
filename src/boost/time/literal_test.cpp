#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <assert.h>

using namespace boost::gregorian;
using namespace std;

days operator"" _D(unsigned long long n) //后缀为_D, 返回天
{
    return days(n);
}

weeks operator"" _W(unsigned long long n)  
{
    return weeks(n);
}

date operator"" _YWD(const char *s, std::size_t)
{
    from_string(s);
}

int main()
{
    auto d = 10_D;
    auto w = 1_W;

    assert(d.days() == 10);
    assert(w.days() == (7_D).days());

    auto today = "2018/3/24"_YWD;
    cout << today << endl;
}