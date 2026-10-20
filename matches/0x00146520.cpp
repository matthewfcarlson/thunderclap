#include "compat/ptr.h"
extern "C" char DAT_00412f44[];
struct SlowMotionTrack {
    char pad0[8];
    int refs;
    int zero;
    float d;
    float e;
    float a;
    float b;
    char flag;
    void Init();
};
extern "C" void* __cdecl alloc(hulk_uintptr);

SlowMotionTrack* __cdecl target() {
    SlowMotionTrack* p = (SlowMotionTrack*)alloc(0x24);
    if (p) {
        p->Init();
        p->a = 1.0f;
        p->b = 1.0f;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00412f44);
        p->zero = 0;
        p->d = 0.1f;
        p->e = 0.9f;
        p->flag = 0;
        p->refs = 1;
        return p;
    }
    return 0;
}
