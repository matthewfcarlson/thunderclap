#include "compat/ptr.h"
extern "C" char hulk_at_0048e0f0[];
extern "C" char hulk_at_0048e100[];
class Function_d5fd0 {
  public:
    virtual void f();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    int x;
    Function_d5fd0(const char*, int);
};
extern "C" unsigned char __cdecl get(hulk_uintptr);
class Method1_d5fd0 : public Function_d5fd0 {
  public:
    virtual void f();
    Method1_d5fd0(const char* s, int n) : Function_d5fd0(s, 1) {
        x = n;
        b = get(((hulk_intptr)hulk_at_0048e100));
        a = get(((hulk_intptr)hulk_at_0048e0f0));
    }
};
class Closure1_d5fd0 : public Method1_d5fd0 {
  public:
    virtual void f();
    int y;
    Closure1_d5fd0(const char*, int, int);
};
Closure1_d5fd0::Closure1_d5fd0(const char* s, int x, int y) : Method1_d5fd0(s, y) {
    this->y = x;
}