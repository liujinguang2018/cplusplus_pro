#include <algorithm>
#include <iostream>
#include <iterator>
#include <string.h>

using namespace std;

void test_string()
{
    const char S1[] = "Hello, world!";
    const char S2[] = "world";

    const int N1 = strlen(S1);
    const int N2 = strlen(S2);

    const char *p = search(S1, S1 + N1, S2, S2 + N2);
    if (p != S1 + N1)
    {
        printf("Found substring \"%s\" at character %d of string \"%s\".\n", S2, p - S1, S1);
    }
    else
    {
        printf("Couldn't find substring");
    }
}

template <class Integer>
struct congruent
{
    congruent(Integer mod) : N(mod) {}

    bool operator()(Integer a, Integer b) const
    {
        return (a - b) % N == 0;
    }

    Integer N;
};

//寻找三数形成的子序列，三数的最末一个阿拉伯数字为1， 2， 3
void test_array()
{
    int A[10] = {23, 46, 81, 2, 43, 19, 14, 98, 72, 51};
    int digits[3] = {1, 2, 3};

    int *seq = search(A, A + 10, digits, digits + 3, congruent<int>(10));
    if (seq != A + 10)
    {
        cout << "Subsequence: ";
        copy(seq, seq + 3, ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    else
    {
        cout << "Subsequence not found." << endl;
    }
}

int main()
{
    test_string();

    test_array();
}