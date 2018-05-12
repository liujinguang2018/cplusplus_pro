#include "decorator.h"

#include <iostream>
using namespace std;

Component::Component()
{
    cout << "Component()" << endl;
}

Component::~Component()
{
    cout << "~Component()" << endl;
}

void Component::operation()
{
    cout << "Component::operation()" << endl;
}

ConcreteComponent::ConcreteComponent()
{
    cout << "ConcreteComponent()" << endl;
}

ConcreteComponent::~ConcreteComponent()
{
    cout << "~ConcreteComponent()" << endl;
}

void ConcreteComponent::operation()
{
    cout << "ConcreteComponent::operation()" << endl;
}

Decorator::Decorator(Component *comp)
{
    comp_ = comp;
    cout << "Decorator()" << endl;
}

Decorator::~Decorator()
{
    delete comp_;
    cout << "~Decorator()" << endl;
}

void Decorator::operation()
{
    //comp_->operation();
}

ConcreteDecorator::ConcreteDecorator(Component *comp) : Decorator(comp)
{

}

ConcreteDecorator::~ConcreteDecorator()
{

}

void ConcreteDecorator::addBehavior() 
{
    cout << "ConcreteDecorator::addBehavior()" << endl;
}

void ConcreteDecorator::operation()
{
    comp_->operation();
    addBehavior();
}

