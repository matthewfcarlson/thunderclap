#include "decls/data/engine/audio.h"

extern "C" int atexit(void (*)());
struct ListenerEffectPs2Type_35fb00 {
    void Init();
};
extern void Cleanup();
void FUN_0035fb00() {
    (*(ListenerEffectPs2Type_35fb00*)&DAT_004e6548).Init();
    atexit(Cleanup);
}
