#include "compat/ptr.h"
#include "gen/pure3d.h"

struct SceneGraphVisibilityAnimationController_nv_2a7c30 {
    void init(pure3d::SceneGraphVisibilityAnimationController*);
    void setup(int);
};
extern void* __cdecl alloc(unsigned int);
extern int vtable_2a7c30;

void* pure3d::SceneGraphVisibilityAnimationController::vfunc_4() {
    pure3d::SceneGraphVisibilityAnimationController* p = (pure3d::SceneGraphVisibilityAnimationController*)alloc(0x48);
    if (p) {
        ((SceneGraphVisibilityAnimationController_nv_2a7c30*)(p))->init(this);
        *(hulk_intptr*)p = (hulk_intptr)&vtable_2a7c30;
        (*(int *)&p->f_40) = (*(int *)&this->f_40);
        p->f_44 = 0;
        ((SceneGraphVisibilityAnimationController_nv_2a7c30*)(p))->setup(1);
        p->f_44 = this->f_44;
        return (void*)(p);
    }
    return (void*)(0);
}
