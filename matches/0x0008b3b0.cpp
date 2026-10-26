#include "decls/data/game/global.h"
// data: key = DAT_0048e0f0

struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl get(const char*);
struct Function_8b3b0 : public CtorV_001d0480 {
    Function_8b3b0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_8b3b0 {
  public:
    virtual void f();
    char p0[12];
    unsigned char a;
    char p1[7];
    unsigned char b;
    char p2[3];
    const char* name;
    Method1(const char* s, const char* n) : Function_8b3b0(s) {
        name = n;
        b = get(((const char*)&DAT_0048e0f0));
        a = get(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    const char* val;
    Closure1(const char* s, const char* v, const char* n);
};
Closure1::Closure1(const char* s, const char* v, const char* n) : Method1(s, n) {
    val = v;
}
