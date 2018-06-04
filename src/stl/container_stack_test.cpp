#include <stack>
#include <iostream>
#include <assert.h>
using namespace std;

int main(int argc, char *argv[])
{
    stack<int> S;
    
    S.push(8);
    S.push(7);
    S.push(4);

    assert(S.size() == 3);

    assert(S.top() == 4);
    S.pop();

    assert(S.top() == 7);
    S.pop();    

    assert(S.top() == 8);
    S.pop();        

    assert(S.empty());
}