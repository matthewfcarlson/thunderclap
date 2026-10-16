#include "gen/pure3d.h"

typedef unsigned int u32_2a9c50;
struct Obj_2a9c50 {
    virtual void f0();
};
struct Ent_2a9c50 {
    virtual void a();
    virtual void b();
};
extern int rttiA_2a9c50, rttiB;
extern Obj_2a9c50* cast(void*, int, int*, int*, int);

void pure3d::BillboardQuadGroupAnimationController::vfunc_5(void* __p0) { Obj_2a9c50 * p = (Obj_2a9c50 *)__p0;

    Obj_2a9c50* x = cast(p, 0, &rttiA_2a9c50, &rttiB, 0);
    if (x)
        x->f0();
    if ((*(Ent_2a9c50 * *)&this->f_40))
        (*(Ent_2a9c50 * *)&this->f_40)->b();
    (*(Ent_2a9c50 * *)&this->f_40) = (Ent_2a9c50*)x;
}
