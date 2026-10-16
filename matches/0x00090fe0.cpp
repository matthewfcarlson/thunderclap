#include "decls/address.h"
class CStatsManager;
extern "C" void __stdcall FUN_001d0480(void*, int);
extern const char g1[];
extern const char g2[];
class Base {
  public:
    Base(void* p) { FUN_001d0480(p, 1); }
};
class Method1 : public Base {
  public:
    virtual void Invoke(int);
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    CStatsManager* manager;
    Method1(void*, CStatsManager*);
};
Method1::Method1(void* p, CStatsManager* m) : Base(p) {
    manager = m;
    b = FUN_001d04d0(g1);
    a = FUN_001d04d0(g2);
}
class Closure1 : public Method1 {
  public:
    virtual void Invoke(int);
    void* extra;
    Closure1(void*, void*, CStatsManager*);
};
Closure1::Closure1(void* p, void* x, CStatsManager* m) : Method1(p, m) {
    extra = x;
}