//有个小孩上楼梯，楼梯一共有n阶台阶，小孩一次可以上1阶，2阶，3阶。
//实现算法，计算有多少种上楼梯的方法

//求解思路：自上而下，最后一部可能从n-1阶往上走1阶，从n-2阶往上走2阶，从n-3阶往上走3阶
#include <iostream>
using namespace std;

int count_ways(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3);
    }
}

int count_ways_dp(int res[], int n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (res[n] > -1)
    {
        return res[n];
    }
    else
    {
        res[n] = count_ways_dp(res, n - 1) + count_ways_dp(res, n - 2) + count_ways_dp(res, n - 3);

        return res[n];
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << count_ways(i) << " ";
    }
    cout << endl;

    int res[10];
    for (int i = 0; i < 10; i++)
    {
        res[i] = -1;
    }   
    for (int i = 0; i < 10; i++)
    {
        cout << count_ways_dp(res, i) << " ";
    }
    cout << endl;     
}