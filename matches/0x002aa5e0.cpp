#include "gen/pure3d.h"

class ParticleGeneratorHandler_2aa5e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned char vfunc_3(unsigned int);
    virtual void f4();
};

unsigned char pure3d::DefaultParticleGeneratorHandler::vfunc_3(unsigned int x) {
    return x >= 0x15b00 && x <= 0x15b02;
}
