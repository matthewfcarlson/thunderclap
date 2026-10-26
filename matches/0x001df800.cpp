#include "decls/data/game/global.h"

class Function_1df800 {
  public:
    Function_1df800(const char*, int);
    virtual void a();
};
extern "C" unsigned char __cdecl F(const char*);
class Method2 : public Function_1df800 {
  public:
    char p0[12];
    unsigned char b10, b11;
    char p12[6];
    unsigned char b18;
    char p19[3];
    int x1c;
    virtual void a();
    Method2(const char*, int);
};
Method2::Method2(const char* s, int x) : Function_1df800(s, 2) {
    x1c = x;
    b18 = F(((const char*)&DAT_0048e0e4));
    b10 = F(((const char*)&DAT_0048e0f0));
    b11 = F(((const char*)&DAT_0048e0e4));
}