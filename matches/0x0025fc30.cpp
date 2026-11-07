// om::MetaType's scalar deleting destructor (slot 0): the destructor body of 0x0025fa80 inlined, then the delete
// (0x00247550 on the om allocator 0x004e79d0) when bit 0 of the flag is set.
#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"
// data: g_count_25fc30 = DAT_004e79b8.count, g_ptr = DAT_004cd360

extern "C" char DAT_0042aa40[];
namespace om { class MetaType {
  public:
    virtual MetaType* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
}; }
extern "C" void __cdecl FUN_0025f390(void *, void *);
extern "C" void FUN_00247550(void* p, om::MetaType* self);
om::MetaType* om::MetaType::vfunc_0(unsigned char param) {
    void* p = (*(void**)&DAT_004cd360);
    *(void**)this = (void*)((hulk_intptr)DAT_0042aa40);
    FUN_0025f390(p, this);
    DAT_004e79b8.count = DAT_004e79b8.count - 1;
    if (param & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e79d0), this);
    return this;
}
