#include "compat/ptr.h"
#if !defined(HULK_PTR64)
class Drive {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
};

class IRefCount {
  public:
    virtual void vfunc_2(int);
};

class XboxDrive : public Drive, public IRefCount {
  public:
    void vfunc_2(int);
};


XboxDrive g_xbox;
#else
// The 64-bit builds: the code above is a compiler-generated adjustor thunk of an invented class (`this - 4`, then
// the slot), whose adjustment and target are the invented layout's. Here the thunk is explicit: core::XboxDrive's
// BaseObject slot 2 takes the BaseObject sub-object, steps back to the drive by that base's offset in records.h CoreDrive,
// and runs the deleting destructor 0x0026f760 (named by its address, so the native link binds it). The function is
// named by its own address: native_mac.TreeDefs finds the vftable slot's definition by that name (as 0x002786f0).
#include "decls/data/records.h"
struct Target_26f530 {
    void* FUN_0026f760(unsigned char flags);
};
struct Thunk_26f530 {
    void* FUN_0026f530(unsigned char flags);
};
void* Thunk_26f530::FUN_0026f530(unsigned char flags) {
    char* drive = (char*)this - (hulk_uintptr)&((CoreDrive*)0)->vftableObject;
    return ((Target_26f530*)drive)->FUN_0026f760(flags);
}
#endif
