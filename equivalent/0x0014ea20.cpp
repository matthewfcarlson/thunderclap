// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_6 @ 0x0014ea20
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Contact {
    char pad00[0x50];
    int target;           // 0x50
};

struct Fighter {
    char pad00[0x328];
    int currentTarget;    // 0x328
};

struct Body {
    Fighter* FUN_00059a30();
};

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Contact* v3();
    Body* FUN_000592a0();
};

namespace hulkfight {
namespace motion {

class CollisionTargetIsTargetCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void* a1, Target* target, void* a3);

    char pad04[8];
    unsigned char expected;   // 0x0c
};

}
}

bool hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_6(void* a1, Target* target, void* a3)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    Fighter* fighter = target->FUN_000592a0()->FUN_00059a30();
    Contact* contact = target->v3();
    if (contact == 0)
        return false;
    return (contact->target == fighter->currentTarget) == expected;
}
