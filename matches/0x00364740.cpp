// cl-flags: /O1
#include "decls/data/engine/audio.h"
// data: hulk_at_004e7b08 = DAT_004e7b08

#include "compat/ptr.h"
extern void* g_target_364740;
class Obj_364740 {
  public:
    void Run();
};
void __stdcall FUN_00364740() {
    ((Obj_364740*)((hulk_intptr)(DAT_004e7b08 + 0x48)))->Run();
}
