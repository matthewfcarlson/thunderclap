#include "compat/ptr.h"
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
class Base_2b0060 {
  public:
    Base_2b0060();
    virtual void f0();
    char pad[0x0c];
};
class ExprGroup_2b0060 : public Base_2b0060 {
  public:
    unsigned int *a, *a2;
    char pad2[8];
    unsigned int *b, *b2;
    unsigned int *c, *c2;
    ExprGroup_2b0060(unsigned int n);
    virtual void f1();
};
ExprGroup_2b0060::ExprGroup_2b0060(unsigned int n) {
    if (n > 0) {
        a = (unsigned int*)FUN_0008d6d0(n * 4);
        if (a) {
            a2 = a + n;
            goto L;
        }
    }
    a = 0;
    a2 = 0;
L:
    b = 0;
    b2 = 0;
    if (n > 0) {
        c = (unsigned int*)FUN_0008d6d0(n * 4);
        if (c) {
            c2 = c + n;
            return;
        }
    }
    c = 0;
    c2 = 0;
}
