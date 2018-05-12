#ifndef __TALK_H__
#define __TALK_H__

#include <string>
#include <memory>
using namespace std;

class Talk
{
  public:
    Talk(string name, int duration); 

    static shared_ptr<Talk> parse_input_line(string line);

    inline int get_duration();

    inline string &get_name();
    const static int LIGHTENING_MINUTES;
    
    const static string NETWORKING_TALK_NAME;
    const static int NETWORKING_TALK_DURATION;

    const static string LUNCH_NAME;
    const static int LUNCH_DURATION;

    const static int MAX_NAME_LEN;    

  private:
    string name_;
    int duration_;
};

int Talk::get_duration()
{
    return duration_;
}

string &Talk::get_name()
{
    return name_;
}

#endif
