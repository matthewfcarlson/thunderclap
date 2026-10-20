#include "compat/ptr.h"
#include "gen/content.h"

typedef unsigned int u32_21650;
extern const int type_animation;
extern const int type_refcount;
extern void __cdecl Cast(hulk_uintptr, int, const int*, const int*, int);

template <> void content::LoadInventory::DynamicCaster<pure3d::Animation>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}
