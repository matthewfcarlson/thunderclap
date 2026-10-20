#include "gen/pure3d.h"

class Ref_28b760 {
  public:
    virtual void v0();
    virtual void v1();
};
class Elem_28b760 {
  public:
    char d[8];
    ~Elem_28b760() throw();
};
void operator delete(void*);

void pure3d::StringChannel::vfunc_1() {
    if ((*(Ref_28b760 *volatile *)&this->f_0c) == 0 && (*(Elem_28b760 * *)&this->f_18) != 0) {
        int* base = (int*)(*(Elem_28b760 * *)&this->f_18) - 1;
        int n = *base;
        Elem_28b760* e = (*(Elem_28b760 * *)&this->f_18) + n;
        n--;
        if (n >= 0) {
            int c = n + 1;
            do {
                e--;
                e->~Elem_28b760();
                c--;
            } while (c != 0);
        }
        operator delete(base);
    }
    (*(Elem_28b760 * *)&this->f_18) = 0;
    if ((*(Ref_28b760 *volatile *)&this->f_0c) == 0) {
        operator delete((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
    } else {
        Ref_28b760* r = (*(Ref_28b760 *volatile *)&this->f_0c);
        if (r != 0) {
            r->v1();
            (*(Ref_28b760 *volatile *)&this->f_0c) = 0;
        }
        (*(void * *)&this->f_14) = 0;
    }
}
