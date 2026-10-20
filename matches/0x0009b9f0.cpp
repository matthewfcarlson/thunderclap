#include "compat/ptr.h"
extern "C" char hulk_at_0048e128[];
class Base {
  public:
    Base(int, int);
    virtual void f();
};
class Method0_9b9f0 : public Base {
  public:
    Method0_9b9f0(int, int);
    virtual void f();
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    int value;
};
unsigned char __cdecl fun2(hulk_intptr);
Method0_9b9f0::Method0_9b9f0(int a, int b) : Base(a, 0) {
    value = b;
    flag = fun2(((hulk_intptr)hulk_at_0048e128));
}