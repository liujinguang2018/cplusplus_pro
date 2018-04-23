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
    Foo() : val(0), pnext(nullptr) {}


    int val;
    Foo *pnext;
};


//如果class A内含有一个或一个以上的member class objects，那么class A的
//每一个constructor必须调用每一个member class的default construcotr.
//编译器会扩张已存在的constructors，在其中安插一些代码，使得user code
//在被执行之前，先调用必要的default constructors.
//C++语言要求以"member objects在class中的声明次序"来调用各个constructors.
class Bar
{
  public:
    Bar() : str(nullptr) {}

  private:
    char *str;
    Foo foo;
};

Foo global_foo; ///global objects的内存会在程序激活的时候被清零

int main()
{
    Foo foo; ////至于栈中，不一定被清零
    cout << "local foo: " << foo.val << "," << foo.pnext << endl;
    cout << "global foo: " << global_foo.val << "," << global_foo.pnext << endl;
}

// 如果一个没有任何constructors的class派生自一个"带有default constructor"的
// base calss,那么这个derived class的default constructor会被合成出来，它
// 将调用上一层的base classes的default constructor(根据它们的声明次序)。对
// 一个后继派生的class而言，这个合成的constructor和一个“被明确提供的default
// constructor"没有什么差异


//另外两种情况，需要合成出default constructor
//1. class声明（或继承）一个virtual function
//2. class派生自一个继承串联，其中一个或更多的virtual base classes
//用于初始化合成出来的vptr初始值

//在合成的default constructor中，只有base class subobjects和member class
//objects会被初始化。所有其它的nonstatic data member（如整数、指针、整数数组）
//都不会被初始化。这些初始化操作对程序而言或许有需求，但对编译器则非必要
//如果程序需要把一个"把某指针设为0”的default constructor，那么提供它的人
//应该是程序员