#include "gen/global.h"

class Ref {
  public:
    virtual void f0();
    virtual void release();
    int pad;
    int a;
    int b;
};

void CChaseCamera::vfunc_32(int a, int b) {
    Ref* q = (*(Ref *volatile *)&this->f_350);
    if (q && q->a == a && q->b == b) {
        Ref* r = (*(Ref *volatile *)&this->f_350);
        if (r) {
            r->release();
            (*(Ref *volatile *)&this->f_350) = 0;
        }
    }
}
