#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

struct A_16540 {
    A_16540* get();
    int remove(void*, int);
};
struct B_16540 {
    A_16540* get();
};
struct Manager_16540 {
    char pad[0xc];
    A_16540* obj;
};
extern Manager_16540* volatile gManager_16540;

bool CSmartPropRemoveInstanceAction::vfunc_6(int ) {
    A_16540* a = (*(B_16540 * *)&this->f_1c)->get();
    a = a->get();
    hulk_intptr x = ((int)((owners::C_35ef0 *)a)->FUN_00035ef0((hulk_intptr)((*(void * *)&this->f_20))));
    if (x)
        gManager_16540->obj->remove((void*)x, 1);
    return false;
}
