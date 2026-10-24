#include "gen/pure3d.h"

class Item_29bba0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Ref_29bba0 {
  public:
    virtual void a();
    virtual void Destroy();
};

void pure3d::DisplayList::FUN_0029bba0() {
    unsigned int i = 0;
    while (i < (*(unsigned int *)&this->f_10)) {
        (*(Item_29bba0 ** *)&this->f_1c)[i]->f();
        ++i;
    }
    unsigned int j = 0;
    unsigned int off = 0;
    while (j < (*(unsigned int *)&this->f_14)) {
        Ref_29bba0** p = (Ref_29bba0**)((char*)(*(void * *)&this->f_28) + off + 0x40);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        p = (Ref_29bba0**)((char*)(*(void * *)&this->f_28) + off + 0x44);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        ++j;
        off += 0x48;
    }
    (*(unsigned int *)&this->f_14) = 0;
}
