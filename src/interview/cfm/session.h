#ifndef __SESSION_H__
#define __SESSION_H__

#include "talk.h"

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Session
{
  public:
    Session(int duration, int start_time);
    void add_talk(shared_ptr<Talk> talk);
    void fill_with_talk(vector<shared_ptr<Talk>> &talks);
    void output_talks();
    inline bool has_space_for(shared_ptr<Talk> &talk);
    inline int get_remaining_duration();
    enum time_duration {
        MORNING_SESSION_DURATION = 180, 
        LUNCH_SESSION_DURATION = 60,
        AFTERNOON_SESSION_DURATION = 240,
        NETWORKING_SESSION_DURATION = 60,
        MONING_SESSION_START_TIME = 9 * 60,
        LUNCH_SESSION_START_TIME = MONING_SESSION_START_TIME + MORNING_SESSION_DURATION,
        AFTERNOON_SESSION_START_TIME = LUNCH_SESSION_START_TIME + LUNCH_SESSION_DURATION,
        NETWORKING_SESSION_START_TIME_MIN = 16 * 60, //4:00 PM
        NETWORKING_SESSION_START_TIME_MAX = 17 * 60 //4:00 PM
        };

  private:
    vector<shared_ptr<Talk>> talks_;
    int start_time_;
    int remaining_duration_;
};

bool Session::has_space_for(shared_ptr<Talk> &talk)
{
  return remaining_duration_ > talk->get_duration();
}

int Session::get_remaining_duration()
{
  return remaining_duration_;
}

#endif
