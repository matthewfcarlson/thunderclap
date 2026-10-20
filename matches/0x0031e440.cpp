#include "compat/ptr.h"
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}