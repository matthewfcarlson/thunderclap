// Same code shape as 0x002a7540 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

class Other_2d3b20 {
  public:
    hulk_intptr helper(pure3d::ParticlePlaneGenerator*);
};
extern "C" void* __cdecl allocate(hulk_intptr);

void* pure3d::ParticlePlaneGenerator::vfunc_4() {
    pure3d::ParticlePlaneGenerator* self = this;
    Other_2d3b20* p = (Other_2d3b20*)allocate(0x60);
    if (p)
        return (void*)(p->helper(self));
    return (void*)(0);
}
