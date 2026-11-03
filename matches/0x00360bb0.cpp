#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" void __cdecl FUN_00254760();
extern "C" void __cdecl FUN_00364590();
extern "C" int atexit(void(__cdecl*)(void));
struct G_360bb0 {
};
extern "C" void __cdecl FUN_00360bb0() {
    ((audio::SeqEventSilenceType *)&((*(G_360bb0*)&DAT_004e72f8)))->FUN_00254760();
    atexit(FUN_00364590);
}
