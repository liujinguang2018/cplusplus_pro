#include <iostream>
#include <map>
#include <string>

using namespace std;

//C++11/14扩展了using关键字的能力，可以完成typedef相同的工作
using int64 = long;       //别名
using llong = long long;

template<typename T>
using int_map = map<int, T>;

int main()
{
    int_map<string> m;

    static_assert(sizeof(int) == 4, "int must be 32bit");
}

