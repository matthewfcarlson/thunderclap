#include "decls/data/game/global.h"

extern "C" unsigned char __cdecl query(const void*);
class Function_1e1320 {
  public:
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    Function_1e1320(void*, int);
};
class Method1_1e1320 : public Function_1e1320 {
  public:
    virtual void fn();
    Method1_1e1320(void* p, int v) : Function_1e1320(p, 1) {
        x = v;
        b = query(((const char*)&DAT_0048e100));
        a = query(((const char*)&DAT_0048e134));
    }
};
class Closure1_1e1320 : public Method1_1e1320 {
  public:
    virtual void fn();
    int y;
    Closure1_1e1320(void*, int, int);
};
Closure1_1e1320::Closure1_1e1320(void* p, int v, int w) : Method1_1e1320(p, w) {
    y = v;
}