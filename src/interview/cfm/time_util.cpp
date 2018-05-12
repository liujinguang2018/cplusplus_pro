#include "time_util.h"

#include <sstream>

string TimeUtil::minutes_to_time_displayed(int minutes) 
{
    int max_minutes = 60 * 24 - 1;

    if (minutes > max_minutes) {
        throw invalid_argument("invalid minutes");
    }

    stringstream ss;

    int hours = minutes / 60;
    if (hours == 12)
    {
        ss << hours << ":";
    }
    else if (hours % 12 < 10)
    {
        ss << "0" << hours % 12 << ":";
    }
    else 
    {
        ss << hours % 12 << ":";
    }

    minutes = minutes % 60;
    if (minutes < 10)
    {
        ss << "0" << minutes;
    }
    else
    {
        ss << minutes;
    }

    if (hours < 12) 
    {
        ss << "AM";
    }
    else
    {
        ss << "PM";
    }

    return ss.str();
}