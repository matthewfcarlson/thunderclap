#include "gen/global.h"

class M_e8420 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void start(int);
    virtual void end(int);
};
class Item_e8420 {
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
    virtual void run();
};
struct Holder_e8420 {
    M_e8420* m;
    void exec(float, float, float);
};
extern Holder_e8420* gHolder_e8420;

void FEThingsBase::vfunc_10() {
    if ((*(Item_e8420 * *)&this->f_1760)) {
        if (this->f_1830) {
            gHolder_e8420->m->start(0);
            gHolder_e8420->exec((*(float *)&this->f_1834), (*(float *)&this->f_1834), (*(float *)&this->f_1834));
        }
        (*(Item_e8420 * *)&this->f_1760)->run();
        if (this->f_1830)
            gHolder_e8420->m->end(0);
    }
}
