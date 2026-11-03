#include "decls/data/engine/audio.h"
// data: name_250fe0 = DAT_0042989c, pool_250fe0 = DAT_004e6bc8

#include "compat/ptr.h"
#include "gen/audio.h"
#include "gen/owners.h"

extern "C" char DAT_00429d1c[];
typedef unsigned int u32_250fe0;
struct E_250fe0 {
    void init();
};
struct S_250fe0 {
};
extern "C" void* FUN_00247530(void*);

void* audio::SeqEventStopTrackType::vfunc_3() {
    E_250fe0* p = (E_250fe0*)FUN_00247530(((char*)&DAT_004e6bc8));
    if (p) {
        p->init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00429d1c);
        ((u32_250fe0*)p)[2] = 0;
        ((u32_250fe0*)p)[3] = 0;
        ((owners::String_23fc40 *)(((S_250fe0*)((char*)p + 0x10))))->FUN_0023fc40((const char *)(((char*)&DAT_0042989c)), (hulk_intptr)2);
        *((char*)p + 0x1c) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
