#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

void test_case01()
{
    int A1[] = {3, 1, 4, 1, 5, 9, 3};
    int A2[] = {3, 1, 4, 1, 5, 9, 3};

    const int N = sizeof(A1) / sizeof(A1[0]);

    pair<int *, int *> result = mismatch(A1, A1+N, A2);

    if (result.first == A1 + N)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "First mismatch is in position " << result.first - A1 << endl;
        cout << "Values: " << *result.first  << "," << *result.second << endl;
    }
}

inline bool eq_nocase(char c1, char c2)
{
    return toupper(c1) == toupper(c2);
}

void test_case02()
{
    const char *s1 = "This is a test";
    const char *s2 = "This is a aast!!";
    const int N = strlen(s1); //sizeof(s1) / sizeof(s1[0]);
    //cout << N << endl;

    pair<const char *, const char *> result = mismatch(s1, s1 + N, s2, eq_nocase);

    if (result.first == s1 + N)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "The two strings do not differ " << result.first - s1 << endl;
        cout << "Values: " << *result.first  << "," << *result.second << endl;
        //cout << "Not Equal" << endl;
    }
}

int main()
{
    test_case01();
    test_case02();
}