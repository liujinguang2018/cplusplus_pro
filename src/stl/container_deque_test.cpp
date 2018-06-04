#include <deque>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    deque<int> Q;
    Q.push_back(3);
    Q.push_front(1);
    Q.insert(Q.begin() + 1, 2);
    copy(Q.begin(), Q.end(), ostream_iterator<int>(cout, " "));
}