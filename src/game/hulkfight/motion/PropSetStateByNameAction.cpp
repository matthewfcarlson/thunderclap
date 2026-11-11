// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00182070..0x001820d0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropSetStateByNameAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f45137ab {
#define TREE_TU_END }
namespace fn_f45137ab {} using namespace fn_f45137ab;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f45137ab {
struct A_182070 {
    void* f();
};
struct B_182070 {
    int f();
};
struct C_182070 {
    int f(int);
};
struct D {
    int f(int*);
};

} // namespace fn_f45137ab

// 0x00182070 hulkfight::motion::PropSetStateByNameAction::vfunc_5 (89 B): matches/0x00182070.cpp
// sym: ?vfunc_5@PropSetStateByNameAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropSetStateByNameAction::vfunc_5(hulk_intptr __p0, int __p1) { unsigned int param = (unsigned int)__p0;

    if (param == 0 && (*(A_182070 * *)&this->f_20) != 0) {
        A_182070* p = (A_182070*)(*(A_182070 * *)&this->f_20)->f();
        hulk_intptr x = ((B_182070*)p)->f();
        int index = (*(int * *)&this->f_1c)[4];
        if (x != 0) {
            if (index < 0)
                x = *(int*)((char*)x + 0x128);
            else {
                if (index >= 8)
                    return false;
                x = ((C_182070*)x)->f(index);
            }
            if (x != 0)
                ((D*)x)->f((int*)((char*)(*(int * *)&this->f_1c) + 0x18));
        }
    }
    return false;
}

