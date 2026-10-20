#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"

extern "C" char DAT_004324a8[];
typedef unsigned char u8_31ba30;
void __fastcall InitDevice(void*);
void CleanupDevice(void*);
class Device_31ba30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Device_31ba30* f3(u8_31ba30);
};
Device_31ba30* Device_31ba30::f3(u8_31ba30 param) {
    *(volatile int*)((hulk_intptr)DAT_005554a4) = 0;
    *(void**)this = (void*)((hulk_intptr)DAT_004324a8);
    InitDevice((void*)(this));
    if (param & 1)
        CleanupDevice(this);
    return this;
}