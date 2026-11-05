#include "decls/data/engine/audio.h"

extern "C" int atexit(void (*)());
struct ListenerEffectPs2Type_35fb00 {
    void FUN_0024d9e0();
};
extern void FUN_00364310();
void FUN_0035fb00() {
    (*(ListenerEffectPs2Type_35fb00*)&DAT_004e6548).FUN_0024d9e0();
    atexit(FUN_00364310);
}
