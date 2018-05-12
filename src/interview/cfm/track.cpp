#include "track.h"

Track::Track() : sessions_()
{}

void Track::output_session()
{
    for(vector<shared_ptr<Session>>::iterator iter = sessions_.begin(); iter != sessions_.end(); ++iter)
    {
        (*iter)->output_talks();
    }
}

