#include "compat/ptr.h"
#include "gen/global.h"

struct A_16540 {
    A_16540* get();
    int find(void*);
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
    hulk_intptr x = a->find((*(void * *)&this->f_20));
    if (x)
        gManager_16540->obj->remove((void*)x, 1);
    return false;
}
