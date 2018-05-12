#ifndef __TRACK_H__
#define __TRACK_H__

#include "session.h"

#include <vector>
#include <memory>
using namespace std;

class Track
{
  public:
    Track();
    inline void add_session(shared_ptr<Session> session);
    void output_session();

  private:
    vector<shared_ptr<Session>> sessions_;
};

void Track::add_session(shared_ptr<Session> session)
{
    sessions_.push_back(session);
}

#endif
