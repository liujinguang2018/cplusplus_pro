#include <boost/format.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>


int main() {
    boost::posix_time::ptime time_now = boost::posix_time::microsec_clock::local_time();

    boost::posix_time::time_duration td = time_now.time_of_day();

    boost::format fmt = boost::format("%02d%02d%02d%03d") % td.hours() % td.minutes() % td.seconds() % (td.total_milliseconds() % 1000);

    std::cout << fmt.str() << std::endl;
    std::cout << td << std::endl;
}