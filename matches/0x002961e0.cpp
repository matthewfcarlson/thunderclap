#include "decls/data/engine/pure3d/scenegraph.h"
// data: gState_2961e0 = DAT_0052cb98

typedef unsigned int u32_2961e0;
class B_2961e0 {
  public:
    virtual u32_2961e0 a0();
    virtual u32_2961e0 a1();
    virtual u32_2961e0 a2();
    virtual u32_2961e0 a3();
    virtual u32_2961e0 a4();
    virtual u32_2961e0 a5();
    virtual u32_2961e0 a6();
    virtual u32_2961e0 a7();
    virtual u32_2961e0 a8();
    virtual u32_2961e0 a9();
    virtual u32_2961e0 a10();
    virtual u32_2961e0 a11();
    virtual u32_2961e0 a12();
    virtual u32_2961e0 a13();
    virtual u32_2961e0 a14();
    virtual u32_2961e0 a15(u32_2961e0, u32_2961e0, u32_2961e0, u32_2961e0, u32_2961e0);
};
class A_2961e0 {
  public:
    char pad[0x40];
    B_2961e0* p;
    u32_2961e0 f(u32_2961e0 a, u32_2961e0 b, u32_2961e0 c, u32_2961e0 d);
};
u32_2961e0 A_2961e0::f(u32_2961e0 a, u32_2961e0 b, u32_2961e0 c, u32_2961e0 d) {
    if (p) {
        (*(int*)&DAT_0052cb98) = 0;
        return p->a15(a, b, 2, c, d);
    }
    return 0;
}
