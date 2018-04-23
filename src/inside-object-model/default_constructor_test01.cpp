#include <iostream>
using namespace std;

///由编译器生成的缺省构造函数不一定能正常工作，另外，是否生成default constructor视编译器需求

//如果一个class没有任何constructor，但它内含一个member object, 而后者
//有default constructor, 编译器需要为此class合成出一个default constructor,
//但合成出default constructor只负责调用成员对象的default constructor来处理
//对应的成员变量，但它并不产生任何代码来初始化非member object变量

class Foo
{
  public:
    int val;
    Foo *pnext;
};

Foo global_foo; ///global objects的内存会在程序激活的时候被清零

int main()
{
    Foo foo; ////至于栈中，不一定被清零
    cout << "local foo: " << foo.val << "," << foo.pnext << endl;
    cout << "global foo: " << global_foo.val << "," << global_foo.pnext << endl;
}