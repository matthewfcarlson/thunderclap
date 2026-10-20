#include "compat/ptr.h"
typedef unsigned int u32_12e6e0;
extern void* LocationVtable_12e6e0;
extern void __cdecl ReleaseThing(u32_12e6e0);
class Obj_12e6e0 {
  public:
    u32_12e6e0 x[7];
    void Finish();
};
void __fastcall FUN_0012e6e0(Obj_12e6e0* p) {
    p->x[0] = (hulk_uintptr)&LocationVtable_12e6e0;
    ReleaseThing(p->x[4]);
    ReleaseThing(p->x[6]);
    p->Finish();
}
