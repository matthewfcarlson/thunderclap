#include "gen/pure3d.h"

typedef unsigned int u32_2a7b60;
struct Type_2a7b60 {};
extern Type_2a7b60 EntityType;
extern Type_2a7b60 TransformNodeType;
extern void* __cdecl Cast(void*, int, Type_2a7b60*, Type_2a7b60*, int);

void pure3d::SceneGraphTransformAnimationController::vfunc_5(void* __p0) { void * p = (void *)__p0;

    (*(void * *)&this->f_110) = Cast(p, 0, &EntityType, &TransformNodeType, 0);
}
