#include <iterator>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

void basic_feature()
{
    list<int> L;
    
    L.push_back(3);

    front_insert_iterator<list<int> > ii(L);
    *ii++ = 0;
    *ii++ = 1;
    *ii++ = 2;

    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void reverse()
{
    vector<int> V(100);

    for (int i = 0; i < 100; i++)
    {
        V[i] = i;
    }

    list<int> L;
    copy(V.begin(), V.end(), front_inserter(L));
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
    basic_feature();

    reverse();
}