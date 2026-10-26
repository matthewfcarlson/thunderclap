#include "decls/data/game/global.h"
// data: labelA = DAT_0048e100, labelB = DAT_0048e134

extern "C" unsigned char __cdecl getFlag(const char*);
class Function_1ce060 {
  public:
    virtual void f();
    Function_1ce060(void*, int);
    char pad[12];
};
class Method1 : public Function_1ce060 {
  public:
    virtual void f();
    char m10;
    char gap11[7];
    char m18;
    char gap19[3];
    int m1c;
    Method1(void*, int, int);
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    int m20;
    Closure1(void*, int, int);
};
inline Method1::Method1(void* p, int x, int y) : Function_1ce060(p, 1) {
    m1c = y;
    m18 = getFlag(((char*)&DAT_0048e100));
    m10 = getFlag(((char*)&DAT_0048e134));
}
Closure1::Closure1(void* p, int x, int y) : Method1(p, x, y) {
    m20 = x;
}
