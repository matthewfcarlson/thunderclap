#include "gen/pure3d.h"

struct BillboardQuadGroupAnimationController_nv_2a9c00 {
    void initialize(pure3d::BillboardQuadGroupAnimationController*);
};
extern "C" int BQVtable;
extern "C" void* __cdecl alloc(unsigned int);

void* pure3d::BillboardQuadGroupAnimationController::vfunc_4() {
    pure3d::BillboardQuadGroupAnimationController* p = (pure3d::BillboardQuadGroupAnimationController*)alloc(0x48);
    if (p) {
        ((BillboardQuadGroupAnimationController_nv_2a9c00*)(p))->initialize(this);
        *(int*)p = (int)&BQVtable;
        int* z = (int*)((char*)p + 0x40);
        *z = 0;
        pure3d::BillboardQuadGroupAnimationController* q = (*(pure3d::BillboardQuadGroupAnimationController * *)&this->f_40);
        if (q)
            q->vfunc_0();
        pure3d::BillboardQuadGroupAnimationController* old = (*(pure3d::BillboardQuadGroupAnimationController * *)&p->f_40);
        if (old)
            old->vfunc_1();
        (*(pure3d::BillboardQuadGroupAnimationController * *)&p->f_40) = q;
        return (void*)(p);
    }
    return (void*)(0);
}
