#include <iostream>

using namespace std;

template<int N>
struct Fac
{
    static int f()
    {
        return N * Fac<N-1>::f();
    }
};

template<>
struct Fac<0>
{
    static int f()
    {
        return 1;
    }
};

int main()
{
    cout << Fac<10>::f() << endl;

    return 0;
}