// Same code shape as 0x00021650 (propagated; names are from that function)
#include "gen/content.h"

typedef unsigned int u32_2905c0;
extern const int type_animation;
extern const int type_refcount;
extern void __cdecl Cast(u32_2905c0, int, const int*, const int*, int);

template <> void content::LoadInventory::DynamicCaster<physics::PhysicsObject>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((u32_2905c0)p, 0, &type_refcount, &type_animation, 0);
}
