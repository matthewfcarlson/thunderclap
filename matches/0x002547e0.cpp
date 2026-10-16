#include "gen/audio.h"

extern "C" char DAT_0042a30c[];
typedef unsigned int u32_2547e0;
extern void* __cdecl allocObj(void*);
extern char gPool_2547e0;
struct SeqEventSilence_2547e0 {
    u32_2547e0 vptr;
    u32_2547e0 unk;
    int duration;
    int end;
    void initialize();
};

void* audio::SeqEventSilenceType::vfunc_3() {
    SeqEventSilence_2547e0* p = (SeqEventSilence_2547e0*)allocObj(&gPool_2547e0);
    if (p) {
        p->initialize();
        p->vptr = ((int)DAT_0042a30c);
        p->duration = 500;
        p->end = 1000;
        return (void*)(p);
    }
    return (void*)((SeqEventSilence_2547e0*)0);
}
