#include <memory>
#include <iostream>

using namespace std;

class Int
{
  public:
    Int(int x) : value(x) {}
    int get() { return value; }

  private:
    int value;
};

int main()
{
    Int A[] = {Int(1), Int(2), Int(3)};

    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        cout << A[i].get() << endl;
    }
    cout << "==========================" << endl;

    //construct(A+0, Int(10));
}