#include "decls/data/game/global.h"

extern char b[];
char __cdecl check(const char*);
class Function_1ff9a0 {
  public:
    Function_1ff9a0(const char*, int);
    virtual void f();
};
class Method1_1ff9a0 : public Function_1ff9a0 {
  public:
    inline Method1_1ff9a0(const char* n, void* ctx) : Function_1ff9a0(n, 1) {
        v = ctx;
        y = check(b);
        x = check(((char*)&DAT_0048e0f0));
    }
    virtual void h();
    char pad[0x0c];
    char x;
    char p1[7];
    char y;
    char p2[3];
    void* v;
    void* w;
};
class Closure1_1ff9a0 : public Method1_1ff9a0 {
  public:
    Closure1_1ff9a0(const char*, void*, void*);
    virtual void g();
};
Closure1_1ff9a0::Closure1_1ff9a0(const char* name, void* vec, void* ctx) : Method1_1ff9a0(name, ctx) {
    w = vec;
}
