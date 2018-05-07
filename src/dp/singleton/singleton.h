#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
using namespace std;

class Singleton
{
  public:
    static Singleton *instance();

  protected:
    Singleton(int value);
    ~Singleton();

    ///自动调用析构函数:定义一个静态对象，程序结束时，静态对象必然被析构，
    // 于是在静态对象的析构函数里将单例模式的类也析构了
    class GC  
    {
      public:
        ~GC()
        {
            cout << "GC()" << endl;
            if (instance_)
            {
                cout << "delete instance" << endl;
                delete (instance_);
            }
        }

        GC()
        {
            cout << "GC()" << endl;
        }
    };

  private:
    int value_;
    static Singleton *instance_;
    static GC gc;
};

#endif
