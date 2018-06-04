#include <queue>
#include <iostream>
#include <assert.h>
using namespace std;

int main(int argc, char *argv[])
{
    priority_queue<int> Q;
    Q.push(1);
    Q.push(4);
    Q.push(2);
    Q.push(8);
    Q.push(5);
    Q.push(7);

    assert(Q.size() == 6);

    while (!Q.empty())
    {
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << endl;
}