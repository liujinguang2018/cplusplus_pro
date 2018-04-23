#include <iostream>
using namespace std;

//编译器会对Initialization list一一处理并可能重新排序，以反映出
//members的声明次序，它会安插一些代码到constructor体内，并置于
//任何explicit user code之前
class X {
    public:
        int i;
        int j;
        X(int val) : j(val), i(j) {}
    
};

class Y {
    public:
        int i;
        int j;
        Y(int val) : j(val) {
            i = j;
        }
};

int main()
{
    X x(3);
    Y y(5);

    cout << "x.i = " << x.i << ",x.j=" << x.j << endl;
    cout << "y.i = " << y.i << ",y.j=" << y.j << endl;
}