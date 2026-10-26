#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: textA = DAT_0048e128, textB = DAT_0048e0f0

struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" char __cdecl Check(const char*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* x) : CtorV_001d0480(x, 1) { }
};
class Method : public Base {
  public:
    virtual void f();
    char pad[0xc];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    const char* name;
    float val;
    Method(const char*, float, const char*);
};
class Closure1_2e790 : public Method {
  public:
    virtual void g();
    Closure1_2e790(const char*, float, const char*);
};
Closure1_2e790::Closure1_2e790(const char* x, float y, const char* z) : Method(x, y, z) {
    val = y;
}
Method::Method(const char* x, float y, const char* z) : Base(x) {
    name = z;
    b = Check(((const char*)&DAT_0048e128));
    a = Check(((const char*)&DAT_0048e0f0));
}
