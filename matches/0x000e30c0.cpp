#include "gen/global.h"

class FEControl_e30c0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
};
struct Notifier_e30c0 { void Notify(int); };

void TextSelector::vfunc_25(int p) {
    if (this->f_154 != p) {
        this->f_154 = p;
        if (*(int*)((char*)this + 0x1d94))
            (*(Notifier_e30c0**)((char*)this + 0x1d94))->Notify(p);
        vfunc_0();
    }
}
