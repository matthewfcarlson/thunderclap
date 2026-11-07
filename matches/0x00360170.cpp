#include "decls/data/engine/audio.h"
// data: hulk_at_004e6a60 = DAT_004e6a60

#include "compat/ptr.h"
#include "gen/audio.h"
struct SeqEventWaitBeatType_nv_360170 {
    void FUN_002506d0();
};
extern int __cdecl _atexit(void(__cdecl*)(void));
extern "C" void __cdecl FUN_00364400(void);
void __cdecl FUN_00360170() {
    ((SeqEventWaitBeatType_nv_360170*)(((audio::SeqEventWaitBeatType*)(((audio::SeqEventWaitBeatType*)((hulk_intptr)(((char*)&DAT_004e6a68))))))))->FUN_002506d0();
    _atexit((void(__cdecl*)(void))(hulk_longptr)FUN_00364400);
}
