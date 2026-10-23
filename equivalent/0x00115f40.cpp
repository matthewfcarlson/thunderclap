// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// hulkfight::ai::HasGroundPointCondition::vfunc_6 @ 0x00115f40
#include "gen/hulkfight.h"

namespace fight {
class Params_115f40 {
public:
    virtual void vfunc_0();
};
}
class CFightParams_115f40 : public fight::Params_115f40 {
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

}}
bool hulkfight::ai::HasGroundPointCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_115f40 * params = (fight::Params_115f40 *)__p1; int c = (int)__p2;

    if (!dynamic_cast<CFightParams_115f40*>(params))
        return false;
    Mid_115f40* m = FUN_00059a30(FUN_000592a0(params));
    if (this->f_0d) {
        Slot_115f40* s = m->slot;
        if (!s || s->kind != 1)
            return false;
        Fighter_115f40* f = s->fighter;
        if (!f)
            return false;
        return f->groundPoint == this->f_0c;
    }
    return m->groundPoint == this->f_0c;
}
