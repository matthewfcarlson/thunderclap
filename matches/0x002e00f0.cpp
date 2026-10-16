// Same code shape as 0x002c3140 (propagated; names are from that function)
#include "gen/pure3d.h"

class Helper_2e00f0 {
  public:
    int run(pure3d::PrimGroupSkinnedOptimized*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::PrimGroupSkinnedOptimized::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Helper_2e00f0*)p)->run(this));
    return (void*)(0);
}
