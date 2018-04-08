#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <iterator>
#include <string.h>
#include <assert.h>

using namespace std;

void test_case01()
{
    char A[] = "abcdefg";
    vector<char> V(A, A + strlen(A));

    list<char> L(V.size());
    copy(V.begin(), V.end(), L.begin());
    assert(equal(V.begin(), V.end(), L.begin()));
}

void test_case02()
{
    char A[] = "abcdefg";
    vector<char> V(A, A + strlen(A));

    //L为空，不能直接copy，搭配output iterator adapter来使用copy
    list<char> L;
    copy(V.begin(), V.end(), back_inserter(L));
    assert(equal(V.begin(), V.end(), L.begin()));
}

void test_case03()
{
    list<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);

    copy(L.begin(), L.end(), ostream_iterator<int>(cout, ", "));
}

int main()
{
    test_case01();
    test_case02();
    test_case03();
}