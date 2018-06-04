#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include "component.h"

#include <vector>

using namespace std;

class Composite : public Component
{
  public:
    Composite();
    ~Composite();

    virtual void operation() override;

    virtual void add(Component *) override;
    virtual void remove(Component *) override;

    virtual Component *getChild(int index) override;

  private:
    vector<Component *> comVec;
};

#endif
