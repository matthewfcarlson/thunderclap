// Same code shape as 0x002974d0 (propagated; names are from that function)
#include "gen/pure3d.h"

class Helper_2a3e20 {
  public:
    int call(pure3d::ParticleSystem*);
};
extern void* __cdecl alloc(int);

void* pure3d::ParticleSystem::vfunc_4() {
    void* p = alloc(0xb0);
    if (p)
        return (void*)(((Helper_2a3e20*)p)->call(this));
    return (void*)(0);
}
