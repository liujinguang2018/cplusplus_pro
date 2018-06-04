#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__
#include "builder.h"

class Director
{
  public:
    Director(Builder *bld);
    ~Director();
    void construct();

  private:
    Builder *_bld;
};

#endif
