#include <list>
#include <iostream>
#include <iterator>
#include <assert.h>
using namespace std;

int main()
{
    list<int> L1;
    L1.push_back(0);
    L1.push_front(1);
    L1.insert(++L1.begin(), 3); //1, 3, 0

    list<int> L2;
    L2.push_back(4);
    L2.push_front(2);

    L1.sort();
    L2.sort();

    L1.merge(L2); ///有序插入

    assert(L1.size() == 5);
    assert(L2.size() == 0);

    copy(L1.begin(), L1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    L1.reverse();
    copy(L1.begin(), L1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}