#include <algorithm>
#include <iostream>
#include <functional>
#include <string.h>

using namespace std;

template <class T>
struct print : public unary_function<T, void>
{
    print(ostream &out) : os(out), count(0) {}
    void operator()(T x)
    {
        os << x << " ";
        ++count;
    }

    ostream &os;
    int count;
};

int main()
{
    int A[] = {1, 4, 2, 8, 5, 7};
    const int N = sizeof(A) / sizeof(A[0]);
    print<int> p = for_each(A, A+N, print<int>(cout));
    cout << endl << p.count << " objects printed. " << endl;

    cout << endl << "======================" << endl;
    const char *commands[] = {"ls", "pwd", "date"};
    const int NC = sizeof(commands) / sizeof(commands[0]);
    for_each(commands, commands+NC, system);

}