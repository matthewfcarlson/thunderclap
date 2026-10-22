#include "compat/ptr.h"
class O_2f7b70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(int, int, int, int, int);
    virtual void v18();
    virtual void v19();
    virtual void v20(int, int, int, int, int);
};
struct Q_2f7b70 {
    void Fb();
};
class ImpulseBasedCollisionSolver_2f7b70 {
  public:
    void F(O_2f7b70* p, int a3, int a4, hulk_intptr a5, int a6, int a7);
};
void ImpulseBasedCollisionSolver_2f7b70::F(O_2f7b70* p, int a3, int a4, hulk_intptr a5, int a6, int a7) {
    if (p) {
        p->v17(a4, (hulk_intptr)this + 0x24, a3, a6, a7);
        p->v20(a4, a5, a3, a6, a7);
    } else {
        ((Q_2f7b70*)a5)->Fb();
    }
}
