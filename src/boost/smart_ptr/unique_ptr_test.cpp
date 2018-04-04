#include <memory>
#include <iostream>
#include <assert.h>
#include <boost/smart_ptr/make_unique.hpp>

using namespace std;

//unique_ptr用于替代auto_ptr, boost::scoped_ptr, boost::scoped_array
int main()
{
    unique_ptr<int> up(new int);
    assert(up);

    *up = 10;
    up.reset();

    assert(!up);

    //unique_ptr的数组对象用法与scoped_array基本相同，但模板参数中需要声明为数组类型
    unique_ptr<int []> arr(new int[10]);
    assert(arr);

    arr[0] = 10;
    cout << arr[0] << endl;

    arr.reset();
    assert(!arr);

    auto a = boost::make_unique<int[]>(5);  //5个元素的动态数组
    a[0] = 100;
    a[4] = 500;
}