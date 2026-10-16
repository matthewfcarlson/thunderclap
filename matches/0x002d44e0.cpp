#include "gen/pure3d.h"

class Ref_2d44e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
};

void pure3d::SpriteParticleEmitter::vfunc_16() {
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x158) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x168) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x174) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x180) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x194) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x1a0) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x1a8) = 0x3f800000;
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0x1b0) = 0x3f800000;
    if ((*(Ref_2d44e0 * *)&this->f_88))
        (*(Ref_2d44e0 * *)&this->f_88)->j();
}
