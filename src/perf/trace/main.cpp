#include "trace.h"
#include "tracev2.h"
#include <time.h>
#include <iostream>
using namespace std;

int addOnev1(int x)
{
    return x + 1;
}

//不必要的对象创建和后面的清除会对性能造成破坏性影响
int addOnev2(int x)
{
    string name = "addOnev2";
    Trace t(name);

    return x + 1;
}

int addOnev3(int x) // Forget the string object, use a char pointer instead
{
    const char *name = "addOnev3";
    Trace t(name);

    return x + 1;
}

int addOnev4(int x) // Forget the string object, use a char pointer instead
{
    const char *name = "addOnev4";
    Tracev2 t(name);

    return x + 1;
}

int main(int argc, char *argv[])
{
    Trace::traceIsActive = false;

    clock_t c1 = clock();

    for (int i = 0; i < 10000000; i++)
    {
        addOnev1(i);
    }

    clock_t c2 = clock();

    cout << "Ticks without trace: " << c2 - c1 << endl;

    ////////////////////////////////////////////////
    c1 = clock();

    for (int i = 0; i < 10000000; i++)
    {
        addOnev2(i);
    }

    c2 = clock();
    cout << "Ticks with trace: " << c2 - c1 << endl;

    ////////////////////////////////////////////////
    c1 = clock();

    for (int i = 0; i < 10000000; i++)
    {
        addOnev3(i);
    }

    c2 = clock();
    cout << "Ticks with trace using char pointer: " << c2 - c1 << endl;

    ////////////////////////////////////////////////
    c1 = clock();

    for (int i = 0; i < 10000000; i++)
    {
        addOnev4(i);
    }

    c2 = clock();
    cout << "Ticks with tracev2 using char pointer: " << c2 - c1 << endl;    
}