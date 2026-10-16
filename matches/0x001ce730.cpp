#include "decls/address.h"
class CScenarioManager;
void __stdcall FUN_001d0480(const char*, int);
struct Base {
    Base(const char* a) { FUN_001d0480(a, 1); }
};
class Method1 : public Base {
  public:
    virtual void fn();
    char pad[12];
    unsigned char b10;
    char pad2[7];
    unsigned char b18;
    char pad3[3];
    int arg;
    Method1(const char*, int);
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    int extra;
    Closure1(const char*, int, int);
};
extern const char g0[], g1[];
inline Method1::Method1(const char* a, int c) : Base(a) {
    arg = c;
    b18 = FUN_001d04d0(g0);
    b10 = FUN_001d04d0(g1);
}
Closure1::Closure1(const char* a, int b, int c) : Method1(a, c) {
    extra = b;
}
