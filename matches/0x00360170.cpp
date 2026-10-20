#include "gen/audio.h"
extern "C" char hulk_at_004e6a60[];
struct SeqEventWaitBeatType_nv_360170 {
    void Run();
};
extern int __cdecl _atexit(void(__cdecl*)(void));
extern void __cdecl FUN_00364400(void);
void __cdecl FUN_00360170() {
    ((SeqEventWaitBeatType_nv_360170*)(((audio::SeqEventWaitBeatType*)((int)(hulk_at_004e6a60 + 0x8)))))->Run();
    _atexit((void(__cdecl*)(void))(long)FUN_00364400);
}
