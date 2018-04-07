#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

void test_case01()
{
    int A1[] = {3, 1, 4, 1, 5, 9, 3};
    int A2[] = {3, 1, 4, 1, 5, 9, 4};

    const int N = sizeof(A1) / sizeof(A1[0]);

    if (equal(A1, A1 + N, A2))
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
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
    cout << N << endl;

    if (equal(s1, s1 + N, s2, eq_nocase))
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
}

int main()
{
    test_case01();
    test_case02();
}