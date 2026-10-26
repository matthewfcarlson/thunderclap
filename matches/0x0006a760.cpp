#include "compat/ptr.h"
#include "gen/global.h"

class A_6a760 {
  public:
    char pad[0x33c];
    A_6a760* Next();
};
class B_6a760 {
  public:
    A_6a760* Get();
};
class D {
  public:
    int Run(COrientTargetTrack*, void*, int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
extern D* __cdecl FUN_0001fc60(void*);

hulk_intptr COrientTargetTrack::vfunc_12(hulk_intptr __p0) { void * p = (void *)__p0;

    B_6a760* b = (B_6a760*)p;
    A_6a760* a = b->Get();
    a = a->Next();
    int v = *(int*)((char*)a + 0x338);
    if (!v)
        v = *(int*)((char*)a + 0x334);
    if (!v)
        v = *(int*)((char*)a + 0x330);
    if (v) {
        D* d = (D*)FUN_0008d690(0x2c);
        if (d)
            return d->Run(this, p, v);
    }
    return 0;
}
