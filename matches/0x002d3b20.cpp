// Same code shape as 0x002a7540 (propagated; names are from that function)
#include "gen/pure3d.h"

class Other_2d3b20 {
  public:
    int helper(pure3d::ParticlePlaneGenerator*);
};
extern "C" void* __cdecl allocate(int);

void* pure3d::ParticlePlaneGenerator::vfunc_4() {
    pure3d::ParticlePlaneGenerator* self = this;
    Other_2d3b20* p = (Other_2d3b20*)allocate(0x60);
    if (p)
        return (void*)(p->helper(self));
    return (void*)(0);
}
