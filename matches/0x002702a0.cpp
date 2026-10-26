#include "decls/data/engine/core.h"

#include "compat/ptr.h"
extern "C" hulk_intptr FUN_00266e00(hulk_intptr, int);
class Obj_2702a0 {
  public:
    virtual void Finish();
    void Init(int, int, int, int, int, int, int);
};
class MemoryPool_2702a0 {
  public:
    Obj_2702a0* Create();
};
void Target(Obj_2702a0** out, int a, int b, int c, int d, int e, int f) {
    DAT_004cdbb0 = d;
    MemoryPool_2702a0* p = (MemoryPool_2702a0*)FUN_00266e00(d, 0x34);
    Obj_2702a0* obj;
    if (p)
        obj = p->Create();
    else
        obj = 0;
    obj->Init(0, a, b, c, d, e, f);
    obj->Finish();
    *out = obj;
}
