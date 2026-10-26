#include "decls/data/game/global.h"

struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Get(const char*);
class InitBase : public CtorV_001d0480 {
  public:
    InitBase(const char* name) : CtorV_001d0480(name, 1) { }
};
class Closure1_1ffd80 : public InitBase {
  public:
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    int z;
    Closure1_1ffd80(const char*, int);
};
Closure1_1ffd80::Closure1_1ffd80(const char* name, int v) : InitBase(name) {
    z = v;
    y = Get(((const char*)&DAT_0048e0f0));
    x = Get(((const char*)&DAT_0048e134));
}
class Closure1 : public Closure1_1ffd80 {
  public:
    virtual void f();
    int val;
    Closure1(const char*, int, int);
};
Closure1::Closure1(const char* name, int v, int w) : Closure1_1ffd80(name, w) {
    val = v;
}
