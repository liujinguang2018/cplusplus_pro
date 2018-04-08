#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <iterator>
#include <string.h>
#include <assert.h>

using namespace std;

void test_replace()
{
    vector<string> fruits;
    fruits.push_back("cherry");
    fruits.push_back("apple");
    fruits.push_back("peach");
    fruits.push_back("plum");
    fruits.push_back("pear");

    replace(fruits.begin(), fruits.end(), string("apple"), string("orange"));

    copy(fruits.begin(), fruits.end(), ostream_iterator<string>(cout, ", "));
    cout << endl;
}

void test_replace_if_01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(-3);
    v.push_back(2);
    v.push_back(-1);

    replace_if(v.begin(), v.end(), bind2nd(less<double>(), 0), 0);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
}

struct string_length_exceeds
{
    string_length_exceeds(int n) : limit(n) {}
    bool operator()(const string &s)
    {
        return s.size() > limit;
    }

    int limit;
};

void test_replace_if_02()
{
    string A[7] = {"oxygen", "carbon", "nitrogen", "iron", "sodiym", "hydrogen", "silicon"};

    replace_if(A, A+7, string_length_exceeds(6), "******");
    copy(A, A+7, ostream_iterator<string>(cout, ", "));
    cout << endl;
}

void test_replace_copy()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);

    replace_copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "), 1, 99);
    cout << endl;
}

void test_replace_copy_if()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(-1);

    replace_copy_if(v.begin(), v.end(), ostream_iterator<int>(cout, ", "), bind2nd(less<int>(), 0), 99);
    cout << endl;
}

int main()
{
    test_replace();

    test_replace_if_01();

    test_replace_if_02();

    test_replace_copy();

    test_replace_copy_if();
}