#include "gen/pure3d.h"

class ParticleGenerator_2d2b90 {
  public:
    virtual void a();
    virtual void b();
};

void pure3d::ParticlePlaneGenerator::vfunc_9() {
    *(int*)((char*)this + 0x4c) = 0x3f800000;
    *(int*)((char*)this + 0x50) = 0x3f800000;
    *(int*)((char*)this + 0x54) = 0x3f800000;
    *(int*)((char*)this + 0x58) = 0x3f800000;
    *(int*)((char*)this + 0x5c) = 0x3f800000;
}
