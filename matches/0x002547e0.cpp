#include "decls/data/engine/audio.h"
// data: gPool_2547e0 = DAT_004e72f8

#include "compat/ptr.h"
#include "gen/audio.h"

extern "C" char DAT_0042a30c[];
typedef unsigned int u32_2547e0;
extern void* __cdecl allocObj(void*);
struct SeqEventSilence_2547e0 {
    hulk_uintptr vptr;
    u32_2547e0 unk;
    int duration;
    int end;
    void initialize();
};

void* audio::SeqEventSilenceType::vfunc_3() {
    SeqEventSilence_2547e0* p = (SeqEventSilence_2547e0*)allocObj(((char*)&DAT_004e72f8));
    if (p) {
        p->initialize();
        p->vptr = ((hulk_intptr)DAT_0042a30c);
        p->duration = 500;
        p->end = 1000;
        return (void*)(p);
    }
    return (void*)((SeqEventSilence_2547e0*)0);
}
