#ifndef __ABSTRACTION_H__
#define __ABSTRACTION_H__

class AbstractionImp;

class Abstraction
{
  public:
    virtual ~Abstraction();
    virtual void operation() = 0;

  protected:
    Abstraction();
};

class RefinedAbstraction : public Abstraction
{
  public:
    RefinedAbstraction(AbstractionImp *imp);
    ~RefinedAbstraction();

    void operation();

  private:
    AbstractionImp *imp_;
};

#endif
