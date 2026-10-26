#include "decls/data/engine/core.h"
// data: g_unknown_26d1b0 = DAT_004cdbb0

#include "compat/ptr.h"
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
void Init();
class RefCount {
  public:
    void* vftable;
    int mRef;
    void* mParam;
    RefCount(int x);
};
RefCount::RefCount(int x) {
    vftable = (void*)((hulk_intptr)DAT_0042afa8);
    mRef = DAT_004cdbb0;
    Init();
    vftable = (void*)((hulk_intptr)DAT_0042b3a4);
    mParam = (void*)x;
    Init();
}