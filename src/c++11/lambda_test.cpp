#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

//lambda表达式的完整声明语法是：
//[captures](params) mutable->type {}

using namespace std;

void test_cast()
{
    auto f = []() { };
    typedef void (*func)(); ///函数指针类型

    func pf1 = f;
    func pf2 = []() { cout << endl; }; ///C接口的互操作性
    //func pf3 = [&](){cout << endl;};  //不能在初始化时将‘test_cast()::<lambda()>’转换为‘func {aka void (*)()}’
    auto f2 = [](auto x) {}; ///泛型表达式
}

void test_capture()
{
    vector<int> v = {1, 2, 3, 4};
    int sum = 0;

    for_each(v.begin(), v.end(),
             [&](int x) {
                 sum += x;
             });
    cout << "sum = " << sum << endl;

    int k = 3;
    auto c = count_if(v.begin(), v.end(),
                      [=](int x) {
                          return x > k;
                      });
    cout << "count if it's greater than k: " << c << endl;

    //lambda表达式还可以使用关键字mutable修饰，它为值方式捕获添加
    //一个例外，允许变量在函数体内也能修改，但只是内部的拷贝，不影响
    //外部变量
    auto f = [=]() mutable { return ++k; };
}

int main()
{
    auto f1 = [](int x) { return x * x; }; //lambda表达式的类型为闭包(closure type), 无法直接给出
    auto f2 = [](string s) { cout << "lambda: " << s << endl; };
    auto f3 = [](int x, int y) -> bool { return x > y; };

    cout << f1(3) << endl;
    f2("heavy rain");
    cout << f3(3, 5) << endl;

    vector<int> v = {1, 2, 3, 5};
    for_each(v.begin(), v.end(), [](int &x) { if (x > 3) x *= 3; });
    //copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    for_each(v.begin(), v.end(), [](int x) { cout << x << ","; });

    cout << "======================" << endl;

    test_capture();
}