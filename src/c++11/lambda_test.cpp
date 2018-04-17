#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#

using namespace std;

int main()
{
    auto f1 = [](int x) { return x * x; }; //lambda表达式的类型为闭包(closure type), 无法直接给出
    auto f2 = [](string s) { cout << "lambda: " << s << endl; };
    auto f3 = [](int x, int y)->bool { return x > y; };

    cout << f1(3) << endl;
    f2("heavy rain");
    cout << f3(3, 5) << endl;

    vector<int> v = {1, 2, 3, 5};
    for_each(v.begin(), v.end(), [](int &x) { if (x > 3) x *= 3; });
    //copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    for_each(v.begin(), v.end(), [](int &x) { cout << x << ","; });

}