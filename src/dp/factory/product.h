#ifndef __PRODUCT_H__
#define __PRODUCT_H__

class Product
{
  public:
    virtual ~Product() = 0; //纯虚函数

  protected:
    Product();
};

class ConcreteProduct : public Product
{
  public:
    ConcreteProduct();
    ~ConcreteProduct();
};

#endif
