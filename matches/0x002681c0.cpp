#include "compat/ptr.h"
typedef unsigned char byte_2681c0;
typedef unsigned int u32_2681c0;
extern void __cdecl FUN_00267090(u32_2681c0);
extern void __cdecl FUN_00266f00(u32_2681c0, void*);
extern u32_2681c0 global_2681c0;
extern int vtMain, vt4, vtBase, vtRef;
struct Helper_2681c0 {
    virtual void f0();
    virtual void f1();
};
class TimerList {
  public:
    virtual void v0();
    virtual void v1();
    virtual TimerList* v2(byte_2681c0);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char p0[4];
    u32_2681c0 field8;
    char pad[12];
    Helper_2681c0* helper;
    u32_2681c0 pad1;
    u32_2681c0 field20;
};
TimerList* TimerList::v2(byte_2681c0 p) {
    u32_2681c0 x = field20;
    *(hulk_uintptr*)this = (hulk_uintptr)&vtMain;
    *((u32_2681c0*)this + 1) = (hulk_uintptr)&vt4;
    FUN_00267090(x);
    helper->f1();
    global_2681c0 = field8;
    *((u32_2681c0*)this + 1) = (hulk_uintptr)&vtBase;
    *(hulk_uintptr*)this = (hulk_uintptr)&vtRef;
    if (p & 1)
        FUN_00266f00(global_2681c0, this);
    return this;
}
