#include "compat/ptr.h"
#if !defined(HULK_PTR64)
class Drive {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    int a;
    int b;
};

class IBase {
  public:
    virtual void w0();
    virtual void w1();
    virtual void v2(int);
};

class XboxDrive : public Drive, public IBase {
  public:
    XboxDrive() {}
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
};

XboxDrive* MakeXboxDrive() {
    return new XboxDrive();
}
#else
// The 64-bit builds: the code above is a compiler-generated adjustor thunk of an invented class (`this - 0xc`, then
// the slot), whose adjustment and target are the invented layout's. Here the thunk is explicit: core::XboxDrive's
// IMutable slot 2 takes the IMutable sub-object, steps back to the drive by that base's offset in records.h CoreDrive,
// and runs the deleting destructor 0x0026f760 (named by its address, so the native link binds it). The function is
// named by its own address: native_mac.TreeDefs finds the vftable slot's definition by that name (as 0x002786f0).
#include "decls/data/records.h"
struct Target_26f540 {
    void* FUN_0026f760(unsigned char flags);
};
struct Thunk_26f540 {
    void* FUN_0026f540(unsigned char flags);
};
void* Thunk_26f540::FUN_0026f540(unsigned char flags) {
    char* drive = (char*)this - (hulk_uintptr)&((CoreDrive*)0)->vftableMutable;
    return ((Target_26f540*)drive)->FUN_0026f760(flags);
}
#endif
