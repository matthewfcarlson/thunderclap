#include "compat/ptr.h"
extern "C" char DAT_0042c48c[];
typedef unsigned int u32_27f830;
struct CMotionTrailQueue {
    hulk_uintptr vtable;
    char pad[0x58];
    u32_27f830 field5c;
    void Run();
    void Finish();
};
extern void __cdecl thunk_FUN_00267090(u32_27f830);
void CMotionTrailQueue::Finish() {
    u32_27f830 x = field5c;
    vtable = ((hulk_intptr)DAT_0042c48c);
    thunk_FUN_00267090(x);
    Run();
}