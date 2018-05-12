#include "talk.h"

#include <regex>
using namespace std;

const string Talk::NETWORKING_TALK_NAME =  "Networking Event";
const int Talk::NETWORKING_TALK_DURATION = 60;
const int Talk::LIGHTENING_MINUTES = 5;
const int Talk::MAX_NAME_LEN = 256;

const string Talk::LUNCH_NAME = "Lunch";
const int Talk::LUNCH_DURATION = 60;

Talk::Talk(string name, int duration) : name_(name), duration_(duration)
{
}

shared_ptr<Talk> Talk::parse_input_line(string line)
{
    if (line.size() == 0)
    {
        return nullptr;
    }

    regex reg("([0-9]+)min|lightning");
    smatch sm;

    if (regex_search(line, sm, reg))
    {
        if (sm.str().compare("lightning") == 0)
        {
            shared_ptr<Talk> talk(new Talk(line, Talk::LIGHTENING_MINUTES));

            return talk;
        }
        else
        {
            shared_ptr<Talk> talk(new Talk(line, atoi(sm.str(1).c_str())));

            return talk;
        }
    }
    else
    {
        return nullptr;
    }
}