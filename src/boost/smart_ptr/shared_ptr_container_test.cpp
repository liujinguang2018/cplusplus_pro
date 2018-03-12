#include <boost/shared_ptr.hpp>

#include <vector>
#include <iostream>

class A
{
  public:
    virtual void sing() = 0;

  protected:
    virtual ~A(){};
};

class B : public A
{
  public:
    virtual void sing()
    {
        std::cout << "Do re mi fa so la" << std::endl;
    }

    ~B(){
        std::cout << "destruction is called" << std::endl;
    }
};

boost::shared_ptr<A> createA()
{
    boost::shared_ptr<A> p(new B());

    return p;
}

int main()
{
    typedef std::vector<boost::shared_ptr<A>> container_type;
    typedef container_type::iterator iterator;

    container_type container;
    for (int i = 0; i < 10; i++)
    {
        container.push_back(createA());
    }

    std::cout << "The choir is gathered: \n";
    iterator end = container.end();
    for (iterator it = container.begin(); it != end; it++)
    {
        (*it)->sing();
    }
}