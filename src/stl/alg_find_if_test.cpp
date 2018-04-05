#include <list>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>
//#include <function.h>

using namespace std;

void test_array()
{
    int A[] = {4, 1, 0, 3, 2, 0, 6};
    const int N = sizeof(A) / sizeof(A[0]);

    int *p = find_if(A, A + N, bind2nd(equal_to<int>(), 0));

    cout << "Index of first zero = " << p - A << endl;
}

void test_pair()
{
    typedef pair<int, const char *> Pair;

    vector<Pair> v;
    v.push_back(Pair(3, "A"));
    v.push_back(Pair(7, "B"));
    v.push_back(Pair(2, "C"));
    v.push_back(Pair(0, "D"));
    v.push_back(Pair(4, "E"));

    //TODO
    //vector<Pair>::iterator iter = find_if(v.begin(), v.end(), compose1(bind2nd(equal_to<int>(), 2), select1st<Pair>()));
}

void test_list()
{
    list<int> l;
    l.push_back(-3);
    l.push_back(0);
    l.push_back(3);
    l.push_back(-2);
    l.push_back(7);

    list<int>::iterator result = find_if(l.begin(), l.end(), bind2nd(greater<int>(), 0));

    assert(result == l.end() || *result > 0);
}

int main()
{
    test_array();

    test_list();
}