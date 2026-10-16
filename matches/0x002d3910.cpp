#include "gen/pure3d.h"

class Helper_2d3910 {
  public:
    int run(pure3d::ParticlePointGenerator*);
};
extern "C" void* __cdecl allocThing(unsigned int);

void* pure3d::ParticlePointGenerator::vfunc_4() {
    void* p = allocThing(0x50);
    if (p)
        return (void*)(((Helper_2d3910*)p)->run(this));
    return (void*)(0);
}
