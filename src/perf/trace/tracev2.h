#ifndef __TRACEV2_H__
#define __TRACEV2_H__

#include <string>
#include <iostream>
using namespace std;

class Tracev2
{
  public:
    Tracev2(const char *name);
    ~Tracev2();
    void debug(const char *name);
    static bool traceIsActive;

  private:
    string* func_name;
};

inline Tracev2::Tracev2(const char *name) : func_name(0)
{
    if (traceIsActive)
    {
        cout << "Enter function " << name << endl;

        func_name = new string(name);
    }
}

inline void Tracev2::debug(const char *msg)
{
    if (traceIsActive)
    {
        cout << msg << endl;
    }    
}

inline Tracev2::~Tracev2()
{
    if (traceIsActive)
    {
        cout << "Exit function " << func_name << endl;

        delete func_name;
    }
}

#endif
