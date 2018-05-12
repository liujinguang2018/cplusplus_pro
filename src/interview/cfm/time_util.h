#ifndef __TIME_UTILS_H__
#define __TIME_UTILS_H__

#include <string>
#include <exception>
using namespace std;

class TimeUtil
{
  public:
    /** 
     *  Description: convert time in minutes to string representation
     *  @param minutes 
     *   
     *  @return the string format is xx:xx AM or xx:xx PM
     */
    static string minutes_to_time_displayed(int minutes);
};

#endif
