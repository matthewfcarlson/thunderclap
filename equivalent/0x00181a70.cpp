// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// hulkfight::motion::CSMPropIsCharacterCondition::vfunc_6 @ 0x00181a70
#include "gen/hulkfight.h"

extern char DAT_00494b44[];
extern char DAT_00494b60[];
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Stats_181a70;

struct Ctx_181a70 {
    Stats_181a70 *FUN_00059a30();
};

class Owner_181a70 {
public:
    Ctx_181a70 *FUN_000592a0();
};

struct Target_181a70 {
    char pad0[0x148];
    int f148;
};

struct Stats_181a70 {
    char pad0[0x3a4];
    struct Slot {
        char pad0[8];
        Target_181a70 *f8;
        int fc;
    } *f3a4;
};

namespace hulkfight { namespace motion {  }}
bool hulkfight::motion::CSMPropIsCharacterCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; Owner_181a70 * owner = (Owner_181a70 *)__p1; int a3 = (int)__p2;

    if (FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    Stats_181a70::Slot *slot = owner->FUN_000592a0()->FUN_00059a30()->f3a4;
    if (slot == 0 || slot->fc != 5)
        return false;
    return (slot->f8->f148 != 0) == (int)(*(unsigned char *)&this->f_0c);
}
