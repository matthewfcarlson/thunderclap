#include "decls/data/game/unknown.h"
// data: hulk_at_0048e128 = DAT_0048e128

#include "compat/ptr.h"
class Function_9b9f0 {
  public:
    Function_9b9f0(int, int);
    virtual void f();
};
class Method0_9b9f0 : public Function_9b9f0 {
  public:
    Method0_9b9f0(int, int);
    virtual void f();
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    int value;
};
unsigned char __cdecl fun2(hulk_intptr);
Method0_9b9f0::Method0_9b9f0(int a, int b) : Function_9b9f0(a, 0) {
    value = b;
    flag = fun2(((hulk_intptr)((char*)&DAT_0048e128)));
}