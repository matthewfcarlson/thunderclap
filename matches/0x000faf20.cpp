// Same code shape as 0x00021650 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/content.h"

typedef unsigned int u32_faf20;
extern const int type_animation;
extern const int type_refcount;
extern void __cdecl Cast(u32_faf20, int, const int*, const int*, int);

template <> void content::LoadInventory::DynamicCaster<DollyScript::CRawScript>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}
