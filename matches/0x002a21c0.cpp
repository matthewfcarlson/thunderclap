#include "compat/ptr.h"
extern "C" char DAT_0042d750[];
extern "C" void _ReadWriteBarrier();
typedef unsigned int u32_2a21c0;
extern void __cdecl thunk_FUN_00267090(u32_2a21c0);
extern void __fastcall FUN_002c6aa0(void*);
struct TranslucentTraversal {
    u32_2a21c0 vptr;
    char pad04[0x18];
    u32_2a21c0 mSeven;
    char pad20[8];
    u32_2a21c0 mTen;
};
void __fastcall FUN_002a21c0(TranslucentTraversal* self) {
    *(volatile hulk_uintptr*)&self->vptr = ((hulk_intptr)DAT_0042d750);
    _ReadWriteBarrier();
    if (self->mTen)
        thunk_FUN_00267090(self->mTen);
    if (self->mSeven)
        thunk_FUN_00267090(self->mSeven);
    FUN_002c6aa0(self);
}
