// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// hulkfight::ai::HasGroundPointCondition::vfunc_6 @ 0x00115f40
namespace fight {
class Params {
public:
    virtual void vfunc_0();
};
}
class CFightParams : public fight::Params {
public:
    virtual void vfunc_0();
};
struct Owner_115f40 {
    char pad[8];
    int state;
    Owner_115f40* next;
    char pad2[0x1a39 - 0x10];
    char groundPoint;
};
struct Fighter_115f40 {
    char pad[0x328];
    Owner_115f40* owner;
    char pad2[0x1a39 - 0x32c];
    char groundPoint;
};
struct Slot_115f40 {
    char pad[8];
    int kind;
    Fighter_115f40* fighter;
};
struct Mid_115f40 {
    char pad[0x328];
    Slot_115f40* slot;
    char pad2[0x1a39 - 0x32c];
    char groundPoint;
};
void* __fastcall FUN_000592a0(void* p);
Mid_115f40* __fastcall FUN_00059a30(void* p);
namespace hulkfight { namespace ai {
class HasGroundPointCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params* params, int c);
    char pad4[8];
    char expected;
    char useOwner;
};
bool HasGroundPointCondition::vfunc_6(int a, fight::Params* params, int c) {
    if (!dynamic_cast<CFightParams*>(params))
        return false;
    Mid_115f40* m = FUN_00059a30(FUN_000592a0(params));
    if (useOwner) {
        Slot_115f40* s = m->slot;
        if (!s || s->kind != 1)
            return false;
        Fighter_115f40* f = s->fighter;
        if (!f)
            return false;
        return f->groundPoint == expected;
    }
    return m->groundPoint == expected;
}
}}
