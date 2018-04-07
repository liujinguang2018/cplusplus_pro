#include <thread>
#include <iostream>

using namespace std;


void hello()
{
    cout << "Hello, concurrency thread." << endl;
} 

int main()
{
    thread t(hello);
    t.join();
    //while (1)
    //{
    //    ;
    //}
}