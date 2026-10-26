#include "compat/ptr.h"
extern void ReleaseThing(void*);
extern int vertex_vftable;
extern int ref_vftable_2d0800;
class VertexOffsetList {
  public:
    int* vptr;
    int p4, p8, pC;
    int a, b, c[4];
    int* d[2];
    void Clear();
};
void VertexOffsetList::Clear() {
atexit:;
    vptr = &vertex_vftable;
    ReleaseThing((void*)a);
    ReleaseThing((void*)b);
    int* p = c;
    int n = 4;
    do {
        ReleaseThing((void*)*(hulk_intptr*)p);
        ++p;
        --n;
    } while (n);
    int** q = d;
    n = 2;
    do {
        if (*q)
            ReleaseThing((char*)*q - 4);
        ++q;
        --n;
    } while (n);
    vptr = &ref_vftable_2d0800;
}