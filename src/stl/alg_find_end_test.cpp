#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    const char *s = "executable.exe";
    const char *suffix = "exe";

    const int N = strlen(s);
    const int N_suf = strlen(suffix);

    const char *location = find_end(s, s + N, suffix, suffix + N_suf);

    if (location != s + N)
    {
        cout << "Found a match for " << suffix << " within " << s << endl;
        cout << s << endl;

        int i;
        for (i = 0; i < (location - s); ++i)
        {
            cout << ' ';
        }
        for (i = 0; i < N_suf; ++i)
        {
            cout << "^";
        }
        cout << endl;
    }
    else
    {
        cout << "No match for " << suffix << " within " << s << endl;
    }
}