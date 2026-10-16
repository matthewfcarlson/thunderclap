#include "gen/pure3d.h"

extern void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Helper_2a83b0 {
    void go();
};
extern char Entity_RTTI;
extern char CompositeDrawable_RTTI;

void pure3d::CompDrawVisibilityAnimationController::vfunc_5(void* __p0) { void * arg = (void *)__p0;

    (*(void * *)&this->f_40) = FUN_00344e74(arg, 0, &Entity_RTTI, &CompositeDrawable_RTTI, 0);
    ((Helper_2a83b0*)this)->go();
}
