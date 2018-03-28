#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v;

    string tmp;
    while (getline(cin, tmp)) {
        v.push_back(tmp);
    }

    cout << "====after sorted====" << endl;
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}
