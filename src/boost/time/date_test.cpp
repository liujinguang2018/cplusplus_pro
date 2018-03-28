#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost::gregorian;
using namespace std;

class CreditCard
{
  public:
    CreditCard(char *bank_name, int bill_day_no)
        : bank_name_(bank_name), bill_day_no_(bill_day_no)
    {
    }

    int calc_free_days(date consume_day = day_clock::local_day()) const
    {
        date bill_day(consume_day.year(), consume_day.month(), bill_day_no_);
        if (consume_day > bill_day) //如果过了，则下个月记账
        {
            bill_day += months(1);
        }

        return (bill_day - consume_day).days() + 20;
    }

    friend bool operator<(const CreditCard &l, const CreditCard &r)
    {
        return l.calc_free_days() < r.calc_free_days();
    }

    string &bank_name()
    {
        return bank_name_;
    }

  private:
    string bank_name_;
    int bill_day_no_;
};

void print_day_week()
{
    date d(2018, 1, 20);
    date d_start(d.year(), d.month(), 1);
    date d_end = d.end_of_month();

    for (day_iterator d_iter(d_start); d_iter != d_end; ++d_iter)
    {
        cout << *d_iter << " " << d_iter->day_of_week() << endl;
    }
    cout << endl;
}

void print_birthday_info()
{
    date d(2000, 3, 24);
    date d18years = d + years(18);

    cout << d18years << " is " << d18years.day_of_week() << endl;

    //星期天计数
    int count = 0;
    for (day_iterator d_iter(date(d18years.year(), d18years.month(), 1)); d_iter != d18years.end_of_month(); ++d_iter)
    {
        if (d_iter->day_of_week() == Sunday)
        {
            ++count;
        }
    }
    cout << "total " << count << " Sundays" << endl;

    count = 0;
    for (month_iterator m_iter(date(d18years.year(), 1, 1)); m_iter < date(d18years.year() + 1, 1, 1); ++m_iter)
    {
        count += m_iter->end_of_month().day();
    }
    cout << "total " << count << " days of year." << endl;
}

int main()
{
    print_day_week();

    //下面的程序计算一个人18岁的生日是星期几，当月有几个星期，当年有多少天
    print_birthday_info();

    CreditCard a("A bank", 25);
    CreditCard b("B bank", 12);

    CreditCard tmp = max(a, b);
    cout << "You should use " << tmp.bank_name() << ", free days = " << tmp.calc_free_days() << endl;
}
