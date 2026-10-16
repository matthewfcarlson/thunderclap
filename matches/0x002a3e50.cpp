#include "gen/pure3d.h"

class Callback_2a3e50 {
  public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void Invoke(int);
};
extern void FUN_002a3b60();

void pure3d::ParticleSystem::vfunc_9() {
    FUN_002a3b60();
    if ((*(class Callback_2a3e50 * *)&this->f_a4))
        (*(class Callback_2a3e50 * *)&this->f_a4)->Invoke(0);
}
