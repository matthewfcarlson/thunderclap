#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: g_value_26ff90 = DAT_004cdbb0

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b5ac[];
extern "C" char DAT_0042b5b4[];
class Ref_26ff90 {
  public:
    virtual void X();
    virtual void A();
};
extern "C" void FUN_00266f20(int, void*);
// core::MemoryPool's destructor body (records.h CoreMemoryPool): releases the child pool, frees the items' block
class MemoryPool_26ff90 : public CoreMemoryPool {
  public:
    void Destroy();
};
void MemoryPool_26ff90::Destroy() {
    Ref_26ff90* p = (Ref_26ff90*)child;
    vftable = DAT_0042b5b4;
    object.vftable = DAT_0042b5ac;
    if (p) {
        p->A();
        child = 0;
    }
    if (heap >= 0)
        FUN_00266f20(heap, blocks);
    *(char* volatile*)&blocks = 0;
    DAT_004cdbb0 = *(volatile int*)&object.heap;
    object.vftable = DAT_0042af64;
    vftable = DAT_003f6098;
}
