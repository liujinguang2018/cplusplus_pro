#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int main()
{
    int A[] = {1, 2, 3, 3, 4, 5};
    const int N = sizeof(A) / sizeof(A[0]);

    const int *p = adjacent_find(A, A + N);

    if (p != A + N)
    {
        cout << "Dumplicate element: " << *p << endl;
    }

    const int *q = adjacent_find(A, A + N, greater<int>());
    if (q == A + N)
    {
        cout << "The range is sorted in ascending order." << endl;
    }
    else
    {
        cout << "Element " << p - A << " is out of order: " 
             << *p << " > " << *(p+1) << "." << endl;
    }
}