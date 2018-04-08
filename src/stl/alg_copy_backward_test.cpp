#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <iterator>
#include <string.h>
#include <assert.h>

using namespace std;

//copy和copy_backward之间唯一的重要差别在于赋值动作，如果input range和output range
//重叠，那么赋值动作的顺序就成为一个要点
int main()
{
    int A[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    copy_backward(A, A+10, A+15);
    
    copy(A, A+15, ostream_iterator<int>(cout, ","));
    cout << endl;
}