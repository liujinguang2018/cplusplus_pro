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

    return 0;
}