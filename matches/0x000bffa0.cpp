#include "decls/data/game/global.h"

struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char lookup(const void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* n) : CtorV_001d0480(n, 1) { }
};
class Closure1_bffa0 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    const char* name;
    Closure1_bffa0(const char*, const char*);
};
class Closure1 : public Closure1_bffa0 {
  public:
    virtual void g();
    void* p;
    Closure1(const char*, void*, const char*);
};
Closure1_bffa0::Closure1_bffa0(const char* n, const char* s) : Base(n) {
    name = s;
    y = lookup(((int*)&DAT_0048e100));
    x = lookup(((int*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* n, void* v, const char* s) : Closure1_bffa0(n, s) {
    p = v;
}