#ifndef __BUILD_H__
#define __BUILD_H__

#include "product.h"
#include <string>
using namespace std;

class Builder
{
  public:
    virtual ~Builder();
    virtual void buildPartA(const string &buildPara) = 0;
    virtual void buildPartB(const string &buildPara) = 0;
    virtual void buildPartC(const string &buildPara) = 0;
    virtual Product *getProduct() = 0;

  protected:
    Builder();
};

class ConcreteBuilder : public Builder
{
  public:
    ConcreteBuilder();
    ~ConcreteBuilder();
    virtual void buildPartA(const string &buildPara) override;
    virtual void buildPartB(const string &buildPara) override;
    virtual void buildPartC(const string &buildPara) override;
    virtual Product *getProduct() override;
};

#endif
