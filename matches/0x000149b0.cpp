#include "gen/global.h"

struct Obj_149b0;
struct Manager_149b0 {
    void* Find(int);
};
struct Root_149b0 {
    char pad[0x44];
    Manager_149b0* mgr;
};
extern Root_149b0* gRoot_149b0;
struct Obj_149b0 {
    void Apply(int, int);
};

void CStunAnimationAction::vfunc_4() {
    int x = *(int*)((char*)(*(void * *)&this->f_1c) + 8);
    Obj_149b0* o = (Obj_149b0*)gRoot_149b0->mgr->Find(x);
    if (o)
        o->Apply((*(int *)&this->f_24), 0);
}
