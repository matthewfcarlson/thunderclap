#include "compat/ptr.h"
typedef unsigned int u32_1f34f0;
struct H {
    void Run();
};
extern void f2(u32_1f34f0);
extern void f3(u32_1f34f0, u32_1f34f0);
extern void f4(u32_1f34f0, u32_1f34f0);
extern void f5(u32_1f34f0);
class Obj_1f34f0 {
  public:
    char p0[4];
    int b;
    hulk_intptr c;
    char p1[4];
    int d;
    char e;
    char p2[3];
    int i;
    void Run();
};
void Obj_1f34f0::Run() {
    if (c)
        ((H*)c)->Run();
    c = 0;
    d = 0;
    if (i) {
        f2(i);
        i = 0;
    }
    if (b) {
        f3(b, 0);
        f4(b, 0x32);
        f5(b);
        b = 0;
    }
    e = 0;
}