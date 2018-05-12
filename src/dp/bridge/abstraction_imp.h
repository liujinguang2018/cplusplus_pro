#ifndef __ABSTRACTION_IMP_H__
#define __ABSTRACTION_IMP_H__

class AbstractionImp
{
  public:
    virtual ~AbstractionImp();
    virtual void operation() = 0;

  protected:
    AbstractionImp();
};

class ConcreteAbstractionImpA : public AbstractionImp
{
  public:
    ConcreteAbstractionImpA();
    ~ConcreteAbstractionImpA();
    virtual void operation() override;
};

class ConcreteAbstractionImpB : public AbstractionImp
{
  public:
    ConcreteAbstractionImpB();
    ~ConcreteAbstractionImpB();
    virtual void operation() override;
};

#endif
