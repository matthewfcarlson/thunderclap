#include "gen/pure3d.h"

extern "C" char DAT_0042de4c[];
struct TextureAnimationController_nv_2a95f0 {
    void Init(pure3d::TextureAnimationController*);
};
extern void* __cdecl Alloc(unsigned int);

void* pure3d::TextureAnimationController::vfunc_4() {
    pure3d::TextureAnimationController* p = (pure3d::TextureAnimationController*)Alloc(0x48);
    if (p) {
        ((TextureAnimationController_nv_2a95f0*)(p))->Init(this);
        *(unsigned int*)p = ((int)DAT_0042de4c);
        (*(pure3d::TextureAnimationController * *)&p->f_40) = 0;
        pure3d::TextureAnimationController* r = (*(pure3d::TextureAnimationController * *)&this->f_40);
        if (r)
            r->vfunc_0();
        if ((*(pure3d::TextureAnimationController * *)&p->f_40))
            (*(pure3d::TextureAnimationController * *)&p->f_40)->vfunc_1();
        (*(pure3d::TextureAnimationController * *)&p->f_40) = r;
    } else {
        return (void*)(0);
    }
    return (void*)(p);
}
