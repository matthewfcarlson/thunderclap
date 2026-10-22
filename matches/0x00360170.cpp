#include "compat/ptr.h"
#include "gen/audio.h"
extern "C" char hulk_at_004e6a60[];
struct SeqEventWaitBeatType_360170 {
    void Run();
};
extern int __cdecl _atexit(void(__cdecl*)(void));
extern void __cdecl FUN_00364400(void);
void __cdecl FUN_00360170() {
    ((SeqEventWaitBeatType_360170*)(((audio::SeqEventWaitBeatType*)((hulk_intptr)(hulk_at_004e6a60 + 0x8)))))->Run();
    _atexit((void(__cdecl*)(void))(hulk_longptr)FUN_00364400);
}
