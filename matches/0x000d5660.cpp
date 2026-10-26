#include "decls/data/game/global.h"

struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl check(const char*);
extern const char s4[];
class Function_d5660 : public CtorV_001d0480 {
  public:
    Function_d5660(const char* str) : CtorV_001d0480(str, 3) { }
};
class Method3_d5660 : public Function_d5660 {
  public:
    virtual void f();
    char pad[12];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    int value;
    Method3_d5660(const char*, int);
};
Method3_d5660::Method3_d5660(const char* str, int n) : Function_d5660(str) {
    value = n;
    d = check(((const char*)&DAT_0048e100));
    a = check(((const char*)&DAT_0048e0f0));
    b = check(((const char*)&DAT_0048e134));
    c = check(s4);
}