// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 14/14)
// hulkfight::ai::FightingOtherNPCCondition::vfunc_6 @ 0x0010d930
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Fighter_10d930 {
    char pad00[0x1d40];
    char flag;            // 0x1d40
};

struct Body_10d930 {
    Fighter_10d930* FUN_00059a30();
};

class Target_10d930 {
public:
    Body_10d930* FUN_000592a0();
};

namespace hulkfight {
namespace ai {

class FightingOtherNPCCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(void* a1, Target_10d930* target, void* a3);

    char pad04[8];
    unsigned int mode;     // 0x0c
};

}
}

char hulkfight::ai::FightingOtherNPCCondition::vfunc_6(void* a1, Target_10d930* target, void* a3)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return 0;
    Fighter_10d930* fighter = target->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return 0;
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
        return fighter->flag;
    case 3:
        return fighter->flag == 0;
    }
    return 0;
}
