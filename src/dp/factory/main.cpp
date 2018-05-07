#include "factory.h"
#include "product.h"

int main()
{
    Factory *factory = new ConcreteFactory();
    Product *product = factory->createProduct();

    delete product;
    delete factory;
}