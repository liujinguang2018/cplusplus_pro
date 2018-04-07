#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <assert.h>

using namespace std;

int main()
{
    const int N = 1000;
    vector<double> v1(N);
    vector<double> v2(N);
    vector<double> sum(N);
    vector<double> res(N);

    generate(v1.begin(), v1.end(), rand);
    fill(v1.begin(), v1.end(), -RAND_MAX / 2.0);

    transform(v1.begin(), v1.end(), v2.begin(), sum.begin(), plus<double>());

    for (int i = 0; i < N; i++) 
    {
        assert(sum[i] == v1[i] + v2[i]);
    }

    transform(v1.begin(), v1.end(), v2.begin(), res.begin(), minus<double>());
    for (int i = 0; i < N; i++) 
    {
        assert(sum[i] == v1[i] + v2[i]);
    }    
}