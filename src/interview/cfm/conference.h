#ifndef __CONFERENCE_H__
#define __CONFERENCE_H__

#include "track.h"

#include <vector>
#include <memory>
using namespace std;

class Conference
{
  public:
    Conference();
    inline void add_track(shared_ptr<Track> track);
    void schedule(vector<shared_ptr<Talk>> &talks);
    void output_result();

  private:
    vector<shared_ptr<Track>> tracks_;
};

void Conference::add_track(shared_ptr<Track> track)
{
    tracks_.push_back(track);
}

#endif
