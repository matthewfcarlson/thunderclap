// Same code shape as 0x00297130 (propagated; names are from that function)
#include "gen/pure3d.h"

class Obj_2d3d00 {
  public:
    int helper(pure3d::ParticleSphereGenerator*);
};
extern Obj_2d3d00* alloc(int);

void* pure3d::ParticleSphereGenerator::vfunc_4() {
    Obj_2d3d00* p = alloc(0x48);
    if (p)
        return (void*)(p->helper(this));
    return (void*)(0);
}
