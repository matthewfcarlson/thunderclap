#include "gen/audio.h"

extern "C" char DAT_00429d1c[];
typedef unsigned int u32_250fe0;
struct E_250fe0 {
    void init();
};
struct S_250fe0 {
    void setup(char*, int);
};
extern void* alloc(void*);
extern char pool_250fe0[1];
extern char name_250fe0[1];

void* audio::SeqEventStopTrackType::vfunc_3() {
    E_250fe0* p = (E_250fe0*)alloc(pool_250fe0);
    if (p) {
        p->init();
        *(u32_250fe0*)p = ((int)DAT_00429d1c);
        ((u32_250fe0*)p)[2] = 0;
        ((u32_250fe0*)p)[3] = 0;
        ((S_250fe0*)((char*)p + 0x10))->setup(name_250fe0, 2);
        *((char*)p + 0x1c) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
