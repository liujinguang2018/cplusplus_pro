#ifndef __ADAPTER_CLASS_H__
#define __ADAPTER_CLASS_H__

class Target
{
  public:
    Target();
    virtual ~Target();
    virtual void Request();
};

class Adaptee
{
  public:
    Adaptee();
    virtual ~Adaptee();
    void SpecificRequest();
};

class Adapter : public Target, private Adaptee
{
  public:
    Adapter();
    ~Adapter();
    virtual void Request() override;
};

#endif
