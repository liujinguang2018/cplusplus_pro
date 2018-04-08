#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <iterator>
#include <string.h>
#include <assert.h>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);

    assert(v1[0] == 1 && v1[1] == 2 && v2[0] == 3 && v2[1] == 4);
    swap_ranges(v1.begin(), v1.end(), v2.begin());
    assert(v2[0] == 1 && v2[1] == 2 && v1[0] == 3 && v1[1] == 4);
}