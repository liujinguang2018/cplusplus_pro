#include <iostream>
using namespace std;

static int count = 0;

unsigned int fib(unsigned int n)
{
    count++;

    if (n < 2)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

unsigned int iterative_fib(unsigned int n) 
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        unsigned result = 1, last = 0;

        for (int i = 2; i < n; i++)
        {
            int tmp = result;
            result += last;
            last = tmp;
        }

        return result;
    }
}

void reverse()
{
    char ch;

    cin.get(ch);
    if (ch != '\n')
    {
        reverse();

        cout.put(ch);
    }
}

int main(int argc, char *argv[])
{
    //reverse();

    //output the count of reverse
    fib(30);
    cout << "reverse count of the fib: " << count << endl; 
}