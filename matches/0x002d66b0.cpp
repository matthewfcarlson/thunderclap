#include "gen/pure3d.h"

class Obj_2d66b0 {
  public:
    int run(pure3d::SpriteParticleEmitter*);
};
extern "C" Obj_2d66b0* alloc(int);

void* pure3d::SpriteParticleEmitter::vfunc_4() {
    Obj_2d66b0* p = alloc(0x1e0);
    if (p)
        return (void*)(p->run(this));
    return (void*)(0);
}
