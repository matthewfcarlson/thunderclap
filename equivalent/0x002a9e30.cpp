// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 13/14, incomplete)
// pure3d::ExpressionAnimationController::vfunc_26 @ 0x002a9e30
#include "gen/pure3d.h"

struct Elem_2a9e30 {
    int FUN_002afe80(void* key);
};
struct Anim_2a9e30 {
    char pad00[0x1c];
    int tag;
    char pad20[8];
    int count;
    void* FUN_00288a10(int i);
};
struct Inner_2a9e30 {
    char pad[0x10];
    Elem_2a9e30* elem;
};

bool pure3d::ExpressionAnimationController::vfunc_26(void* __p0) { Anim_2a9e30 * a = (Anim_2a9e30 *)__p0;

    if (a == 0)
        return (bool)(0);
    if (a->count <= 0)
        return (bool)(0);
    if (a->tag != 0x505845)
        return (bool)(0);
    if ((*(Inner_2a9e30 * *)&this->f_40) != 0) {
        Elem_2a9e30* e = (*(Inner_2a9e30 * *)&this->f_40)->elem;
        int i = 0;
        do {
            void* item = a->FUN_00288a10(i);
            if (e->FUN_002afe80((char*)item + 8) == -1)
                return (bool)(0);
            i++;
        } while (i < a->count);
    }
    return (bool)(1);
}
