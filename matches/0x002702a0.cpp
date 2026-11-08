#include "decls/data/engine/core.h"

#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/owners.h"
extern "C" void* FUN_00266e00(int a, int b);
class Obj_2702a0 {
  public:
    virtual void Finish();
};
// core::MemoryPool (0x00270170 constructs it), named by its constructor's address; its layout (records.h
// CoreMemoryPool), so that the allocation is its size on every target
inline void* operator new(unsigned int, void* p) { return p; }
class FUN_00270170 : public CoreMemoryPool {
  public:
    FUN_00270170();
};
void Target(Obj_2702a0** out, int a, int b, int c, int d, hulk_intptr e, int f) {
    DAT_004cdbb0 = d;
    HULK_SIZE32(FUN_00270170, 0x34);
    void* p = FUN_00266e00(d, (int)sizeof(FUN_00270170));
    Obj_2702a0* obj;
    if (p)
        obj = (Obj_2702a0*)new (p) FUN_00270170;
    else
        obj = 0;
    ((owners::Pool_270020 *)obj)->FUN_00270020((void *)(hulk_uintptr)(int)0, (unsigned)a, (unsigned)b, (unsigned)c, (void *)(hulk_uintptr)(int)d, (hulk_uintptr)e, (unsigned)f);
    obj->Finish();
    *out = obj;
}
