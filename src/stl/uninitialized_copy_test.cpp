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
    int A1[] = {1, 2, 3, 4, 5, 6, 7};
    const int N = sizeof(A1) / sizeof(A1[0]);

    Int* A2 = (Int *)malloc(sizeof(Int) * N);
    uninitialized_copy(A1, A1+N, A2);

    cout << A2[1].get() << endl;
}