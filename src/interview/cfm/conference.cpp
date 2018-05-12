#include "conference.h"

Conference::Conference() : tracks_()
{}


void Conference::schedule(vector<shared_ptr<Talk>> &talks)
{
    cout << "Start to schedule talks..." << endl;
    while (talks.size() > 0)
    {
        shared_ptr<Session> morning_session(
            new Session(Session::time_duration::MORNING_SESSION_DURATION, 
                        Session::time_duration::MONING_SESSION_START_TIME));
        
        morning_session->fill_with_talk(talks);

        shared_ptr<Talk> lunch(new Talk(Talk::LUNCH_NAME, Talk::LUNCH_DURATION));
        shared_ptr<Session> lunch_session(
            new Session(Session::time_duration::LUNCH_SESSION_DURATION,
                        Session::time_duration::LUNCH_SESSION_START_TIME
            ));
        lunch_session->add_talk(lunch);

        shared_ptr<Session> afternoon_session(
            new Session(Session::time_duration::AFTERNOON_SESSION_DURATION,
                        Session::time_duration::AFTERNOON_SESSION_START_TIME
            ));
        afternoon_session->fill_with_talk(talks);

        //calculate the start time for the networking talk
        int start_time = Session::time_duration::NETWORKING_SESSION_START_TIME_MAX - afternoon_session->get_remaining_duration();
        if (start_time < Session::time_duration::NETWORKING_SESSION_START_TIME_MIN)
        {
            start_time = Session::time_duration::NETWORKING_SESSION_START_TIME_MIN;
        }

        shared_ptr<Talk> talk(new Talk(Talk::NETWORKING_TALK_NAME, Talk::NETWORKING_TALK_DURATION));
        shared_ptr<Session> networking_session(
            new Session(Session::time_duration::NETWORKING_SESSION_DURATION,
                        start_time
            ));
        networking_session->add_talk(talk);

        shared_ptr<Track> track(new Track());
        track->add_session(morning_session);
        track->add_session(lunch_session);
        track->add_session(afternoon_session);
        track->add_session(networking_session);

        add_track(track);
    }
    cout << "Done" << endl;
}

void Conference::output_result()
{
    int count = 1;

    for (vector<shared_ptr<Track>>::iterator iter = tracks_.begin(); iter != tracks_.end(); ++iter)
    {
        cout << "Track " << count << ":" << endl;
        (*iter)->output_session();
        cout << endl;

        count++;
    }
}
