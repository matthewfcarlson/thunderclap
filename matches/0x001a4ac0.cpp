#include "gen/hulkfight.h"

extern int RTTI1_1a4ac0, RTTI2;
extern int FUN_00344e74(int, int, int, int, int);
struct Result_1a4ac0 {
    int pad;
    int type;
    char gap[0x20];
    int state;
};
struct Obj_1a4ac0 {
    Result_1a4ac0* get();
};

bool hulkfight::scenario::Event_PropStateDescCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; int c = (int)__p2;

    Obj_1a4ac0* x = (Obj_1a4ac0*)FUN_00344e74(b, 0, (int)&RTTI1_1a4ac0, (int)&RTTI2, 0);
    if (!x)
        return false;
    Result_1a4ac0* r = x->get();
    if (r->type != 0x17)
        return false;
    if (r->state == this->f_0c)
        return true;
    return false;
}
