#include "gen/pure3d.h"

struct SceneGraphTransformAnimationController_nv_2a7730 {
    void First();
    void Second(int);
};
extern void* gVftable_2a7730;

pure3d::SceneGraphTransformAnimationController* pure3d::SceneGraphTransformAnimationController::FUN_002a7730() {
    ((SceneGraphTransformAnimationController_nv_2a7730*)this)->First();
    *(void**)this = &gVftable_2a7730;
    this->f_110 = 0;
    ((SceneGraphTransformAnimationController_nv_2a7730*)this)->Second(1);
    return (pure3d::SceneGraphTransformAnimationController*)(this);
}
