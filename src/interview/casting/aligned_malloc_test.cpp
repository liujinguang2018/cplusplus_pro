#include <iostream>
using namespace std;

//实现2的n次方地址对齐分配内存

void *aligned_malloc(size_t required_bytes, size_t alignment)
{
    int offset = alignment - 1 + sizeof(void *);

    void *p = malloc(required_bytes + offset);
    if (p == NULL)
    {
        return NULL;
    }
    void **q = (void **)(((size_t)(p) + offset) & ~(alignment - 1));
    q[-1] = p;

    return q;
}

void aligned_free(void *p2)
{
    void *p1 = ((void **)p2)[-1];

    free(p1);
}