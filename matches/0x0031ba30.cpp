#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"

extern "C" char DAT_004324a8[];
typedef unsigned char u8_31ba30;
extern "C" void __fastcall FUN_0031bae0(void*);
extern "C" void __cdecl thunk_FUN_00267090(void*);  // the heap's free through its `jmp` thunk
class d3dDevice_31ba30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dDevice_31ba30* f3(u8_31ba30);
};
d3dDevice_31ba30* d3dDevice_31ba30::f3(u8_31ba30 param) {
    *(void* volatile*)&DAT_005554a4 = 0;  // the device slot (a pointer word: config/data-ptrs.json)
    *(void**)this = (void*)((hulk_intptr)DAT_004324a8);
    FUN_0031bae0((void*)(this));
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}