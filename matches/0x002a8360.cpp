#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042dc94[];
typedef unsigned int u32_2a8360;
extern void* __cdecl alloc(unsigned int);

class Obj_2a8360 {
  public:
    u32_2a8360 vf;
    char pad[0x3c];
    u32_2a8360 value;
    u32_2a8360 a44;
    u32_2a8360 a48;
    u32_2a8360 unused4c;
    u32_2a8360 a50;
    u32_2a8360 a54;
    void init(pure3d::CompDrawVisibilityAnimationController*);
    void finish();
};

void* pure3d::CompDrawVisibilityAnimationController::vfunc_4() {
    Obj_2a8360* p = (Obj_2a8360*)alloc(0x60);
    if (p) {
        p->init(this);
        p->value = 0;
        p->vf = ((hulk_intptr)DAT_0042dc94);
        p->a44 = 0;
        p->a48 = 0;
        p->a50 = 0;
        p->a54 = 0;
        p->value = (*(u32_2a8360 *)&this->f_40);
        p->finish();
        return (void*)(p);
    }
    return (void*)(0);
}
