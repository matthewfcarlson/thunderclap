#include "compat/ptr.h"
extern "C" char DAT_0042f190[];
class ParticleAllocator {
  public:
    int mVptr;
    int mValue;
    ParticleAllocator();
};
ParticleAllocator::ParticleAllocator() {
    mValue = 0;
    mVptr = ((hulk_intptr)DAT_0042f190);
}