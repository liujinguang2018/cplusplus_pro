#include <boost/smart_ptr.hpp>
#include <algorithm>
#include <iostream>

using namespace boost;
using namespace std;

int main()
{
    int *arr = new int[100];
    scoped_array<int> sa(arr);

    fill_n(&sa[0], 100, 5);

    sa[10] = sa[20] + sa[30];

    for (int i = 0; i < 100; i++) {
        cout << sa[i] << endl;
    }

}