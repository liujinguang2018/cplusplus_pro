#include <list>
#include <algorithm>
#include <assert.h>

using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(7);

    list<int>::iterator iter = find(l.begin(), l.end(), 7);

    assert(iter != l.end());

    iter = find(l.begin(), l.end(), 10);
    assert(iter == l.end());
}