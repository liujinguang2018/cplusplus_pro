#include "composite.h"
#include "leaf.h"

using namespace std;

int main(int argc, char *argv[])
{
    Leaf * lf = new Leaf();
    lf->operation();

    Composite* com = new Composite();
    com->add(lf);
    com->operation();
}