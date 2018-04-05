#include <list>
#include <iterator>
#include <assert.h>

using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);

    list<int>::iterator iter = l.begin();
    advance(iter, 2);

    assert(iter == l.end());

    assert(distance(l.begin(), l.end()) == l.size());
}