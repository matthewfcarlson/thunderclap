#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct ObjEnd {
    char pad[0x1b28];
    int field;
};
struct ObjMid {
    ObjEnd* Call2();
};
struct ObjA_1673c0 {
    ObjMid* Call1();
};

bool hulkfight::motion::RageModeStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    ObjMid* m = ((ObjA_1673c0*)b)->Call1();
    ObjEnd* e = m->Call2();
    int v = e->field;
    switch (this->f_0c) {
    case 0:
        return v == this->f_10;
    case 1:
        return v != this->f_10;
    default:
        return false;
    }
}
