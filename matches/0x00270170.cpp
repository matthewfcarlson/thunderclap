#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: g_unknown_270170 = DAT_004cdbb0

#include "compat/ptr.h"
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
extern "C" char DAT_0042b5ac[];
extern "C" char DAT_0042b5b4[];
extern "C" char DAT_0042b5f4[];
void FUN_002705f0();
// core::MemoryPool (records.h CoreMemoryPool): the bases' vftables (core::IMemoryPool, core::Object, then
// core::RefCount), then its own; no block and no child pool yet
class MemoryPool_270170 : public CoreMemoryPool {
  public:
    MemoryPool_270170();
};
MemoryPool_270170::MemoryPool_270170() {
    vftable = DAT_0042b5f4;
    object.vftable = DAT_0042afa8;
    object.heap = DAT_004cdbb0;
    FUN_002705f0();
    object.vftable = DAT_0042b3a4;
    refs = 0;
    FUN_002705f0();
    vftable = DAT_0042b5b4;
    object.vftable = DAT_0042b5ac;
    blocks = 0;
    child = 0;
    FUN_002705f0();
}
