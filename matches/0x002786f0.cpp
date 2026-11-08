#include "compat/ptr.h"
#if !defined(HULK_PTR64)
// Same code shape as 0x0026f540 (propagated; names are from that function)
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
// the slot), whose adjustment and target are the invented layout's. Here the thunk is explicit: core::XboxSaveDrive's
// IMutable slot 2 takes the IMutable sub-object, steps back to the drive by that base's offset in records.h
// CoreXboxSaveDrive, and runs the deleting destructor 0x00278a80 (named by its address, so the native link binds it).
// The function is named by its own address: native_mac.TreeDefs finds the vftable slot's definition by that name.
#include "decls/data/records.h"
struct Target_2786f0 {
    void* FUN_00278a80(unsigned char flags);
};
struct Thunk_2786f0 {
    void* FUN_002786f0(unsigned char flags);
};
void* Thunk_2786f0::FUN_002786f0(unsigned char flags) {
    char* drive = (char*)this - (hulk_uintptr)&((CoreXboxSaveDrive*)0)->drive.vftableMutable;
    return ((Target_2786f0*)drive)->FUN_00278a80(flags);
}
#endif
