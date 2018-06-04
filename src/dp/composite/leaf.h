#ifndef _LEAF_H_
#define _LEAF_H_

#include "component.h"

class Leaf : public Component
{
    public:
        Leaf();
        ~Leaf();

        void operation();
};

#endif
