#include "decls/data/engine/unknown.h"
// data: g_mgr_35fac0 = DAT_004e6468

class ListenerEffectXBoxType_35fac0 {
  public:
    void FUN_0024d7d0();
};
extern void FUN_00364340();
extern int __cdecl atexit(void (*)(void));
void FUN_0035fac0() {
    (*(ListenerEffectXBoxType_35fac0*)&DAT_004e6468).FUN_0024d7d0();
    atexit(FUN_00364340);
}
