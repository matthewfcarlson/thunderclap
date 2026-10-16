// Same code shape as 0x002c3140 (propagated; names are from that function)
#include "gen/pure3d.h"

class Helper_2e0540 {
  public:
    int run(pure3d::PrimGroupSkinnedStreamed*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::PrimGroupSkinnedStreamed::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Helper_2e0540*)p)->run(this));
    return (void*)(0);
}
