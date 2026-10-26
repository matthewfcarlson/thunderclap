#include "decls/data/engine/unknown.h"
// data: g_mgr_35fac0 = DAT_004e6468

class ListenerEffectXBoxType_35fac0 {
  public:
    void Init();
};
extern void Cleanup();
extern int __cdecl atexit(void (*)(void));
void FUN_0035fac0() {
    (*(ListenerEffectXBoxType_35fac0*)&DAT_004e6468).Init();
    atexit(Cleanup);
}
