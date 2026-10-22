#include "compat/ptr.h"
struct Ref_2f79f0 {
    virtual void f0();
    virtual void f1();
};
struct SymMatrix_2f79f0 {
    char x[1];
    void init();
};
extern int vt_2f79f0;
class ImpulseBasedCollisionSolver_2f79f0 {
  public:
    virtual void v();
    Ref_2f79f0* a;
    char gap[0x94 - 8];
    SymMatrix_2f79f0 e94;
    char gap2[0xb0 - 0x95];
    SymMatrix_2f79f0 eb0;
    char gap3[0xcc - 0xb1];
    SymMatrix_2f79f0 ecc;
    char gap4[0xfc - 0xcd];
    Ref_2f79f0* b;
    void cleanup();
};
void ImpulseBasedCollisionSolver_2f79f0::cleanup() {
    *(hulk_intptr*)this = (hulk_intptr)&vt_2f79f0;
    if (a)
        a->f1();
    if (b)
        b->f1();
    ecc.init();
    eb0.init();
    e94.init();
}