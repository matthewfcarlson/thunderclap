#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int u32_2a6f40;
typedef unsigned int Type;
struct R_2a6f40 {
    virtual void f0();
    virtual void f1();
};
extern R_2a6f40* Cast(hulk_uintptr, int, Type*, Type*, int);
extern Type entityType;
extern Type geometryType;

void pure3d::VertexAnimController::vfunc_5(void* __p0) { hulk_uintptr p = (hulk_uintptr)__p0;

    R_2a6f40* r = Cast(p, 0, &entityType, &geometryType, 0);
    R_2a6f40* n = *(R_2a6f40**)((char*)r + 0x5c);
    if (n)
        n->f0();
    if ((*(R_2a6f40 * *)&this->f_40))
        (*(R_2a6f40 * *)&this->f_40)->f1();
    (*(R_2a6f40 * *)&this->f_40) = n;
}
