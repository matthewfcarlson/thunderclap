// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 16/16)
// hulkfight::ai::TargetTypeCondition::vfunc_6 @ 0x00124750
extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

struct Kind_124750 {
    char pad0[0xc];
    int kind;               // 0x0c
};

struct Mixer {
    char pad0[0x328];
    Kind_124750* target;           // 0x328
};

struct Context {
    Mixer* FUN_00059a30();
};

struct Entity {
    Context* FUN_000592a0();
};

namespace hulkfight {
namespace ai {
class TargetTypeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused1, Entity* entity, int unused2);
    char pad04[8];
    int mode;               // 0x0c
    int type;               // 0x10
};
}
}

bool hulkfight::ai::TargetTypeCondition::vfunc_6(int unused1, Entity* entity, int unused2)
{
    if (!FUN_00344e74(entity, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Kind_124750* target = entity->FUN_000592a0()->FUN_00059a30()->target;
    if (!target)
        return false;
    int want;
    switch (type) {
    case 0:
        want = 1;
        break;
    case 1:
        want = 5;
        break;
    default:
        return false;
    }
    int kind = target->kind;
    switch (mode) {
    case 0:
        return kind == want;
    case 1:
        return kind != want;
    }
    return false;
}
