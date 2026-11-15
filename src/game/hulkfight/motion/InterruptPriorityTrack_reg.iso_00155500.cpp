// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00155500 FUN_00155500 (95 B): matches/0x00155500.cpp [isolated: merged class would differ: Hit_155500: empty base; on include/gen/ and not mergeable]
// sym: _FUN_00155500
#include "decls/data/game/unknown.h"
// data: g_count_155500 = DAT_004e1064, g_data_155500 = DAT_004e1060

#include "gen/fight.h"
extern "C" void __cdecl FUN_0014c550();
extern "C" char DAT_00414838[];
extern "C" void* FUN_0008d690(unsigned int);
extern "C" void FUN_002347b0(void*, void**, int);
class Param {
  public:
    int a[4];
    int val;
};
class Hit_155500 : public Param {
  public:
};
extern "C" void FUN_00155500() {
    void* temp;
    if (!(*(int*)&DAT_004e1064)) {
        Hit_155500* p = (Hit_155500*)FUN_0008d690(0x18);
        if (p) {
            ((fight::ParamValueBool *)p)->FUN_00234860("hasHitPushback");
            *(hulk_intptr*)p = ((hulk_intptr)DAT_00414838);
            *(hulk_intptr*)((char*)p + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0014c550);
            temp = p;
        } else
            temp = 0;
        FUN_002347b0(((void**)&DAT_004e1060), &temp, 1);
    }
    ++(*(int*)&DAT_004e1064);
}

