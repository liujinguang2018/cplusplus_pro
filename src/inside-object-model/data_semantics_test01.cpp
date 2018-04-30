#include <iostream>
#include <stdio.h>

using namespace std;

class X
{
};
class Y : public virtual X
{
};
class Z : public virtual X
{
};

class A : public Y, public Z
{
};

class Concrete1
{
  private:
    int val;
    char ch1;
};

class Concrete2 : public Concrete1
{
  private:
    char ch2;
};

class Concrete3 : public Concrete2
{
  private:
    char ch3;
};

class Point2D
{
  public:
    Point2D(float x, float y) : x_(x), y_(y) {}

    float x() { return x_; }
    void x(float val) { x_ = val; }

    float y() { return y_; }
    void y(float val) { y_ = val; }

    virtual float z() { return 0.0; }
    virtual void z(float) {}
    virtual void operator+=(Point2D &rhs)
    {
        x_ += rhs.x();
        y_ += rhs.y();
    }

  protected:
    float x_, y_;
};

class Point3D : public Point2D
{
  public:
    Point3D(float x = 0.0, float y = 0.0, float z = 0.0) : Point2D(x, y), z_(z)
    {
    }

    virtual float z() override { return z_; }
    virtual void z(float val) override { z_ = val; }

    virtual void operator+=(Point2D &rhs)
    {
        Point2D::operator+=(rhs);
        z_ += rhs.z();
    }

    //protected:
    float z_;
};

//编译器自动加上的额外data members，用以支持某些语言特性(主要是各种virtual特性)
int main()
{
    cout << "sizeof(X) = " << sizeof(X) << endl;
    cout << "sizeof(Y) = " << sizeof(Y) << endl;
    cout << "sizeof(Z) = " << sizeof(Z) << endl;
    cout << "sizeof(A) = " << sizeof(A) << endl;

    cout << "==============================" << endl;
    cout << "sizeof(Concrete1) = " << sizeof(Concrete1) << endl;
    cout << "sizeof(Concrete2) = " << sizeof(Concrete2) << endl;
    cout << "sizeof(Concrete3) = " << sizeof(Concrete3) << endl;

    cout << "==============================" << endl;
    cout << "sizeof(Point2D) = " << sizeof(Point2D) << endl;
    cout << "sizeof(Point3D) = " << sizeof(Point3D) << endl;
    //cout << "&Point3D::z = " << &Point3D::z << endl;
    printf("&Point3D::z = %p", &Point3D::z_);
}