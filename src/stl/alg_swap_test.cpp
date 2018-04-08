#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <iterator>
#include <string.h>
#include <assert.h>

using namespace std;

int main()
{
    int x = 1;
    int y = 2;

    swap(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    iter_swap(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;
}