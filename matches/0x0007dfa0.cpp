#include "decls/address.h"
#include "decls/data/game/global.h"
// data: a_7dfa0 = DAT_0048e100
class Function_7dfa0 {
  public:
    Function_7dfa0(const char*, int);
    virtual void f();
};
class Method2_7dfa0 : public Function_7dfa0 {
  public:
    Method2_7dfa0(const char*, int);
    virtual void f();
    char pad[0xc];
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int arg;
};
class Closure2_7dfa0 : public Method2_7dfa0 {
  public:
    virtual void f();
    int extra;
    Closure2_7dfa0(const char*, int, int);
};
inline Method2_7dfa0::Method2_7dfa0(const char* s, int v) : Function_7dfa0(s, 2) {
    arg = v;
    z = FUN_001d04d0(((const char*)&DAT_0048e100));
    x = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    y = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
Closure2_7dfa0::Closure2_7dfa0(const char* s, int v, int w) : Method2_7dfa0(s, w) {
    extra = v;
}