#include "compat/ptr.h"
class Ref_b3b80 {
  public:
    virtual void F();
};
extern int vtable_b3b80;
class CSimController {
  public:
    hulk_intptr vt;
    int m;
    Ref_b3b80* p;
    char pad[0x10c];
    CSimController(Ref_b3b80*);
    void Init(void*, int);
};
CSimController::CSimController(Ref_b3b80* q) {
    m = 0;
    vt = (hulk_intptr)&vtable_b3b80;
    p = q;
    q->F();
    Init((char*)this + 0xc, 1);
    Init((char*)this + 0x118, 1);
}