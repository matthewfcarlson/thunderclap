#include "gen/global.h"
#include "decls/data/game/unknown.h"
// data: g_timeFn = DAT_004de948

class ParticleObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void Update(float, int);
};
typedef float(__stdcall* TimeFn)();

void FEParticleSystem::vfunc_2() {
    if ((*(int *)&this->f_2c)) {
        (*(ParticleObject * *)&this->f_28)->Update((*(TimeFn*)&DAT_004de948)() * 1000.0f, 0);
    }
}
