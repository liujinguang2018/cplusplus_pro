#ifndef __ADAPTER_OBJECT_H__
#define __ADAPTER_OBJECT_H__

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

class Adapter : public Target
{
  public:
    Adapter(Adaptee *adaptee);
    ~Adapter();
    virtual void Request() override;

  private:
    Adaptee *adaptee_;
};

#endif
