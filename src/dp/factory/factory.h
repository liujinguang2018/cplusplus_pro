#ifndef __FACTORY_H__
#define __FACTORY_H__

class Product;

class Factory{
    public:
        virtual ~Factory() = 0;
        virtual Product *createProduct() = 0;

    protected:
        Factory();
};

class ConcreteFactory : public Factory {
    public:
        ~ConcreteFactory();
        ConcreteFactory();

        virtual Product* createProduct() override;

};

#endif
