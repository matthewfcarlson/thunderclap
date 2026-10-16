#include "gen/pure3d.h"

class Other_2a7540 {
  public:
    int helper(pure3d::ParticleController*);
};
extern "C" void* __cdecl allocate(int);

void* pure3d::ParticleController::vfunc_4() {
    pure3d::ParticleController* self = this;
    Other_2a7540* p = (Other_2a7540*)allocate(0x60);
    if (p)
        return (void*)(p->helper(self));
    return (void*)(0);
}
