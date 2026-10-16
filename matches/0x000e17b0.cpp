#include "gen/global.h"

extern const float zero_e17b0;
extern const float minusone;
class FEDoAction_e17b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};

class Helper_e17b0 {
  public:
    virtual void a();
    virtual void b(FEDoAnimation*);
    virtual void c();
    virtual void d();
    virtual void e(float);
    virtual float f();
    char pad[0x54];
    int done;
};
struct FEDoAnimation_nv_e17b0 {
    void update();
};

void FEDoAnimation::vfunc_1() {
    Helper_e17b0* h = (*(Helper_e17b0 * *)&this->f_34);
    if (h) {
        if (this->f_40 != zero_e17b0) {
            this->f_3c = h->f();
            ((FEDoAnimation_nv_e17b0*)this)->update();
        } else if (this->f_3c > minusone) {
            h->e(this->f_3c);
        }
        int d = (this->f_50 == 0);
        (*(Helper_e17b0 * *)&this->f_34)->done = d;
        (*(Helper_e17b0 * *)&this->f_34)->b(this);
        this->f_38 = 2;
    }
}
