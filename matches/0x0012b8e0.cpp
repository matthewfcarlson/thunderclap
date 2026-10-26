#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Obj_12b8e0 {
    int Fn(int);
};
struct Inner_12b8e0 {
    char pad[8];
    Obj_12b8e0* obj8;
};
struct Outer_12b8e0 {
    char pad[0x20];
    Inner_12b8e0* inner;
};
extern Outer_12b8e0* gGlobal_12b8e0;

bool hulkfight::ai::ThreatBallAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    if (!this->f_20)
        return false;
    Obj_12b8e0* o = gGlobal_12b8e0->inner->obj8;
    this->f_24 = o->Fn(this->f_1c + 0x30);
    return true;
}
