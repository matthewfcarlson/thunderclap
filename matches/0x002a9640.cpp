#include "gen/pure3d.h"

// the original casts to the game's classes (RTTI 0x0048f610 pure3d::Entity, 0x004ce60c pure3d::DrawablePrimitive,
// 0x0048e000 pure3d::Shader); the shader comes from DrawablePrimitive slot 7, the reference count is core::IRefCount's
void pure3d::TextureAnimationController::vfunc_5(void* __p0) { pure3d::Entity * e = (pure3d::Entity *)__p0;

    pure3d::Shader* r;
    pure3d::DrawablePrimitive* d = dynamic_cast<pure3d::DrawablePrimitive*>(e);
    if (d)
        r = (pure3d::Shader*)d->vfunc_7();
    else
        r = dynamic_cast<pure3d::Shader*>(e);
    if (r)
        r->vfunc_0();
    if ((pure3d::Shader*)this->f_40)
        ((pure3d::Shader*)this->f_40)->vfunc_1();
    this->f_40 = r;
}
