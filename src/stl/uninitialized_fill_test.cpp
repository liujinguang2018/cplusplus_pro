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
    const int N = 20;
    Int i(46);

    Int *A = (Int *) malloc(sizeof(Int) * N);
    uninitialized_fill(A, A+N, i);

    cout << A[0].get() << endl;

    Int val(48);
    uninitialized_fill_n(A, N, val);
    cout << A[0].get() << endl;
}