#include "session.h"
#include "time_util.h"

Session::Session(int duration, int start_time) 
    : talks_(), remaining_duration_(duration), start_time_(start_time)
{
}

void Session::add_talk(shared_ptr<Talk> talk)
{
    talks_.push_back(talk);

    remaining_duration_ -= talk->get_duration();
}

void Session::fill_with_talk(vector<shared_ptr<Talk>> &talks)
{
    for (vector<shared_ptr<Talk>>::iterator iter = talks.begin(); iter != talks.end(); )
    {
        if (has_space_for(*iter))
        {
            add_talk(*iter);
            iter = talks.erase(iter);
        }
        else
        {
            break;
        }
    }
}

void Session::output_talks()
{
    int start_time = start_time_;
    for (vector<shared_ptr<Talk>>::iterator iter = talks_.begin(); iter != talks_.end(); ++iter)
    {
        cout << TimeUtil::minutes_to_time_displayed(start_time) << " " << (*iter)->get_name() << endl;

        start_time += (*iter)->get_duration();
    }
}
