#include "time_util.h"
#include "conference.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    //check input parameters
    if (argc != 2)
    {
        cerr << "conference-track-management [FILE_NAME|FILE_FULL_PATH]" << endl;

        exit(1);
    }

    //open file and checking
    char buffer[512];
    ifstream in(argv[1]);
    if (!in.is_open())
    {
        cerr << "Error opening file " << argv[1] << endl;
        exit(1);
    }

    //load talk from file into vector structure
    vector<shared_ptr<Talk>> talks;
    while (!in.eof())
    {
        in.getline(buffer, sizeof(buffer));

        shared_ptr<Talk> talk = Talk::parse_input_line(buffer);
        if (talk != nullptr)
        {
            talks.push_back(talk);
        }
    }
    in.close();

    shared_ptr<Conference> conference(new Conference());
    conference->schedule(talks);

    cout << "=====Scheduling Result=======" << endl;
    conference->output_result();
    // string s1 = "Writing Fast Tests Against Enterprise Rails 60min";
    // string s2 = "Rails for Python Developers lightning";
    // string s3 = "Rails for Python expert";
    // regex reg("([0-9]+)min|lightning");
    // smatch sm;
    // cout << boolalpha << regex_search(s1, sm, reg) << endl;
    // cout << sm.str(0) << endl;
    // cout << sm.str(1) << endl;
    // cout << sm.str(2) << endl;
    // cout << boolalpha << regex_search(s2, sm, reg) << endl;
    // cout << sm.str() << endl;
    // cout << boolalpha << regex_search(s3, sm, reg) << endl;
    // cout << sm.str() << endl;

    // vector<string> s;
    // s.push_back("Hello");
    // s.push_back("world");
    // s.push_back("Beijing");
    // s.push_back("changping");

    // for (vector<string>::iterator iter = s.begin(); iter != s.end(); ++iter)
    // {
    //     cout << *iter << endl;
    //     if ((*iter).compare("Beijing") == 0)
    //     {
    //         iter = s.erase(iter);
    //     }
    // }

    // cout << endl;
    // for (vector<string>::iterator iter = s.begin(); iter != s.end(); ++iter)
    // {
    //     cout << *iter << endl;
    //     // if ((*iter).compare("Beijing") == 0) {
    //     //     iter = s.erase(iter);
    //     // }
    // }

    return 0;
}