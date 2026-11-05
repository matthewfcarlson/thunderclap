#include "decls/data/engine/core.h"

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" hulk_intptr FUN_00266e00(hulk_intptr, int);
class Obj_2702a0 {
  public:
    virtual void Finish();
};
class MemoryPool_2702a0 {
  public:
    Obj_2702a0* Create();
};
void Target(Obj_2702a0** out, int a, int b, int c, int d, hulk_intptr e, int f) {
    DAT_004cdbb0 = d;
    MemoryPool_2702a0* p = (MemoryPool_2702a0*)FUN_00266e00(d, 0x34);
    Obj_2702a0* obj;
    if (p)
        obj = p->Create();
    else
        obj = 0;
    ((owners::Pool_270020 *)obj)->FUN_00270020((void *)(hulk_uintptr)(int)0, (unsigned)a, (unsigned)b, (unsigned)c, (void *)(hulk_uintptr)(int)d, (hulk_uintptr)e, (unsigned)f);
    obj->Finish();
    *out = obj;
}
