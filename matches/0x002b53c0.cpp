// Same code shape as 0x00224c60 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

class Helper_2b53c0 {
  public:
    hulk_intptr run(pure3d::ShadowMeshImpl*);
};
extern void* thunk_FUN_0008d690(int);

void* pure3d::ShadowMeshImpl::vfunc_4() {
    Helper_2b53c0* p = (Helper_2b53c0*)thunk_FUN_0008d690(0x70);
    if (p)
        return (void*)(p->run(this));
    return (void*)(0);
}
