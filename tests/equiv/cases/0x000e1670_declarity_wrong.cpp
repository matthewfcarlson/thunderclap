#include "gen/global.h"

class ParticleObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void Update(float);
};
typedef float(__stdcall* TimeFn)(int);
extern TimeFn g_timeFn;

void FEParticleSystem::vfunc_2() {
    if ((*(int *)&this->f_2c)) {
        (*(ParticleObject * *)&this->f_28)->Update(g_timeFn(0) * 1000.0f);
    }
}
