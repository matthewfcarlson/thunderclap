// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f2e40..0x001f6bc0 (kind game, layer game, confidence high), dominant class CSoundVoiceManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001f39d0 FUN_001f39d0 (118 B): matches/0x001f39d0.cpp [isolated: conflict: DAT_003f3358; DAT_004c7df8; on include/gen/ and not mergeable]
// sym: ?FUN_001f39d0@Obj_1f39d0@owners@@QAEXM@Z
#include "gen/owners.h"
extern "C" float DAT_004c7df8;
static const float DAT_003f3358 = 0.01f;
extern void __cdecl FUN_00247890(int, float);
void owners::Obj_1f39d0::FUN_001f39d0(float x) {
    DAT_004c7df8 = x;
    if (flag == 0) {
        int i = 0;
        if (count > 0) {
            int* p = (int*)((char*)this + 8);
            do {
                hulk_intptr v = *p;
                if (v != at8c && v != skip) {
                    int q = *(int*)(v + 4);
                    if (q)
                        FUN_00247890(q, DAT_004c7df8 * DAT_003f3358);
                }
                ++i;
                ++p;
            } while (i < count);
        }
    }
}

