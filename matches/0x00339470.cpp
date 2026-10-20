#include "compat/ptr.h"
typedef unsigned int uint;
extern void __cdecl CopyThing(void*, void*, hulk_intptr);
struct Thing_339470 {
    uint* mPtr;
    int mCount;
    void* mArg;
    int mData;
};
extern void __cdecl Finish(Thing_339470*);
int* __cdecl Target(Thing_339470* p) {
    hulk_intptr n = (hulk_intptr)p->mPtr - (hulk_intptr)p - 12;
    if (n != 0) {
        CopyThing(p->mArg, &p->mData, n);
        p->mPtr = (uint*)&p->mData;
        ++p->mCount;
        Finish(p);
    }
    return (int*)&p->mData;
}