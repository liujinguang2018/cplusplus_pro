#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

bool eq_nosign(int x, int y) 
{
    return abs(x) == abs(y);
}

void lookup(int *first, int *last, size_t count, int val)
{
    cout << "Searching for a sequence of " << count 
    << " '" << val << "'" << (count != 1 ? "s: " : ": ");

    int *result = search_n(first, last, count, val);
    if (result == last)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Index = " << result - first << endl;
    }
}

void lookup_nosign(int *first, int *last, size_t count, int val)
{
    cout << "Searching for a (sign-insensitive) sequence of " << count 
    << " '" << val << "'" << (count != 1 ? "s: " : ": ");

    int *result = search_n(first, last, count, val, eq_nosign);
    if (result == last)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Index = " << result - first << endl;
    }
}

int main()
{
    const int N = 10;
    int A[N] = {1, 2, 1, 1, 3, -3, 1, 1, 1, 1};

    lookup(A, A+N, 4, 1);
    lookup(A, A+N, 2, 2);
    lookup_nosign(A, A+N, 2, 3);
}