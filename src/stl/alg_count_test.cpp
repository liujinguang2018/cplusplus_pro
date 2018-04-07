#include <algorithm>
#include <iostream>
#include <functional>
//#include <ext/functional>
#include <string.h>

using namespace std;

int main()
{
    int A[] = {1, 3, 1, 4, -1, 0, 5, 7, 9, 4};
    const int N = sizeof(A) / sizeof(A[0]);

    //int result = 0;
    cout << "Number of zeroes: " << count(A, A + N, 1) << endl;

    cout << "number of which is greater than zero:" << count_if(A, A + N, bind2nd(greater<int>(), 0));
    //TODO  偶数
    //cout << count_if(A, A+N, bind2nd(bind2nd(modulus<int>(), 2), 0) << endl;
    //unary_function();
    //binary_function
}