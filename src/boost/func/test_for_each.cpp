#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

struct square //函数对象
{
    typedef void result_type;
    void operator()(int &x) 
    {
        x = x * x;
    }
};

int main()
{
    typedef double (*pfunc)(double);

    pfunc pf = sqrt;
    cout << std::ref(pf)(5.0) << endl;  //包装函数指针

    vector<int> v = {1, 2, 3, 4, 5, 6};
    //for_each(v.begin(), v.end(), square());
    square sq;
    std::for_each(v.begin(), v.end(), std::ref(sq));  ///支持调用操作符，使得我们可以调用函数对象的引用给标准算法库，boost::ref不支持

    vector<int>::iterator iter = v.begin();
    for (; iter != v.end(); ++iter)
    {
        cout << *iter << endl;
    }    
}