#ifndef __TRACE_H__
#define __TRACE_H__

#include <string>
#include <iostream>
using namespace std;

class Trace
{
  public:
    Trace(const string &name);
    Trace(const char *name);
    ~Trace();
    void debug(const string &msg);
    void debug(const char *name);
    static bool traceIsActive;

  private:
    string func_name;
};

inline Trace::Trace(const string &name) : func_name(name)
{
    if (traceIsActive)
    {
        cout << "Enter function " << name << endl;
    }
}

inline Trace::Trace(const char *name) : func_name(name)
{
    if (traceIsActive)
    {
        cout << "Enter function " << name << endl;
    }
}

inline void Trace::debug(const string &msg)
{
    if (traceIsActive)
    {
        cout << msg << endl;
    }
}

inline void Trace::debug(const char *msg)
{
    if (traceIsActive)
    {
        cout << msg << endl;
    }    
}

inline Trace::~Trace()
{
    if (traceIsActive)
    {
        cout << "Exit function " << func_name << endl;
    }
}

#endif
