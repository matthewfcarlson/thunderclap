#include "compat/ptr.h"
extern "C" char DAT_00400c1c[];
struct CStaticAllocator {
    void* vf;
    char pad[0xC];
    int m10;
    int m14;
    void Reset();
};
void thunk_FUN_00267090(hulk_intptr);
void CStaticAllocator::Reset() {
    vf = (void*)((hulk_intptr)DAT_00400c1c);
    thunk_FUN_00267090(m14);
    thunk_FUN_00267090(m10);
}