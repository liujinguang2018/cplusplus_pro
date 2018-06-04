#include <queue>
#include <iostream>
#include <assert.h>
using namespace std;

int main(int argc, char *argv[])
{
    queue<int> Q;
    Q.push(8);
    Q.push(7);
    Q.push(6);
    Q.push(2);

    assert(Q.size() == 4);
    assert(Q.back() == 2);

    assert(Q.front() == 8);
    Q.pop();

    assert(Q.front() == 7);
    Q.pop();
    assert(Q.front() == 6);
    Q.pop();
    assert(Q.front() == 2);
    Q.pop();

    assert(Q.empty());
}
