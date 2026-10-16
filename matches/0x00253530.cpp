#include "gen/audio.h"

extern "C" void* __cdecl Alloc(void*);
extern int g_pool_253530;
extern int rand_vftable;
struct SeqEventVarPitchRand_253530 {
    int* vf;
    int pad;
    float a;
    float b;
    void init();
};

void* audio::SeqEventVarPitchRandType::vfunc_3() {
    SeqEventVarPitchRand_253530* p = (SeqEventVarPitchRand_253530*)Alloc(&g_pool_253530);
    if (p) {
        p->init();
        p->vf = &rand_vftable;
        p->a = 0.8f;
        p->b = 1.2f;
        return (void*)(p);
    }
    return (void*)(0);
}
