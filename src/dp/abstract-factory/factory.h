#ifndef __FACTORY_H__
#define __FACTORY_H__

class AbstractProductA;
class AbstractProductB;

class AbstractFactory
{
  public:
    virtual ~AbstractFactory();
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;

  protected:
    AbstractFactory();
};

class ConcreteFactory1 : public AbstractFactory
{
    public:
    ConcreteFactory1();
    ~ConcreteFactory1();
    virtual AbstractProductA* createProductA() override;
    virtual AbstractProductB* createProductB() override;
};

class ConcreteFactory2 : public AbstractFactory
{
    public:
    ConcreteFactory2();
    ~ConcreteFactory2();
    virtual AbstractProductA* createProductA() override;
    virtual AbstractProductB* createProductB() override;
};

#endif
