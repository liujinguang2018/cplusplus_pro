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
    const int N = 7;
    double A[N] = {4, 5, 6, 7, 1, 2, 3};
    list<double> L(N);

    transform(A, A+N, L.begin(), negate<double>());

    copy(L.begin(), L.end(), ostream_iterator<double>(cout, ","));
    cout << endl;
}

void test_case02()
{
    const int N = 10;
    vector<int> V(N);

    fill(V.begin(), V.end(), 75);
    
    int A[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    transform(V.begin(), V.end(), A, ostream_iterator<int>(cout, ", "), plus<int>());
}

int main()
{
    test_case01();
    test_case02();
}