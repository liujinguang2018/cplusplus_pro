#include "composite.h"


Composite::Composite()
{

}

Composite::~Composite()
{
    vector<Component* >::iterator iter = comVec.begin();

    for (; iter != comVec.end(); )
    {
        iter = comVec.erase(iter);
    }
}

void Composite::operation()
{
    vector<Component* >::iterator iter = comVec.begin();

    for (; iter != comVec.end(); ++iter)
    {
        (*iter)->operation();
    }
}

void Composite::add(Component* com)
{
    comVec.push_back(com);
}

void Composite::remove(Component *com)
{
    //comVec.erase(&com);
}

Component* Composite::getChild(int index)
{
    return comVec[index];
}
