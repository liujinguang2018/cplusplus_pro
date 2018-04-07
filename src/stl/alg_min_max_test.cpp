#include <algorithm>
#include <iostream>
#include <functional>
#include <list>
#include <iterator>
#include <string.h>
#include <assert.h>

using namespace std;

void test_min()
{
    const int x = min(3, 9);
    assert(x == 3);

    int a = 3;
    int b = 3;
    const int &result = min(a, b);
    assert(&result == &a);
}

void test_max()
{
    const int x = max(3, 9);
    assert(x == 9);

    int a = 3;
    int b = 3;
    const int &result = min(a, b);
    assert(&result == &a);
}

void test_min_element()
{
    list<int> L;

    generate_n(front_inserter(L), 100, rand);
    list<int>::iterator iter = min_element(L.begin(), L.end());

    cout << "The smallest element " << *iter << endl;
}

void test_max_element()
{
    list<int> L;
    generate_n(front_inserter(L), 100, rand);
    list<int>::iterator iter = max_element(L.begin(), L.end());

    cout << "The largest element " << *iter << endl;
}

int main()
{
    test_min();

    test_max();

    test_min_element();

    test_max_element();
}