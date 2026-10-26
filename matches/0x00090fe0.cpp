#include "decls/address.h"
#include "decls/data/game/global.h"
class CStatsManager;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_90fe0 : public Base {
  public:
    virtual void Invoke(int);
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    CStatsManager* manager;
    Closure1_90fe0(void*, CStatsManager*);
};
Closure1_90fe0::Closure1_90fe0(void* p, CStatsManager* m) : Base(p) {
    manager = m;
    b = FUN_001d04d0(((const char*)&DAT_0048e100));
    a = FUN_001d04d0(((const char*)&DAT_0048e134));
}
class Closure1 : public Closure1_90fe0 {
  public:
    virtual void Invoke(int);
    void* extra;
    Closure1(void*, void*, CStatsManager*);
};
Closure1::Closure1(void* p, void* x, CStatsManager* m) : Closure1_90fe0(p, m) {
    extra = x;
}