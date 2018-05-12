#ifndef __DECORATOR_H__
#define __DECORATOR_H__

class Component
{
  public:
    virtual ~Component();
    virtual void operation();

  protected:
    Component();
};

class ConcreteComponent : public Component
{
  public:
    ConcreteComponent();
    ~ConcreteComponent();
    virtual void operation() override;
};

class Decorator : public Component
{
  public:
    Decorator(Component *component);
    ~Decorator();
    virtual void operation() override;

  protected:
    Component *comp_;
};

class ConcreteDecorator : public Decorator
{
  public:
    ConcreteDecorator(Component *component);
    ~ConcreteDecorator();
    virtual void operation() override;
    void addBehavior();
};

#endif
