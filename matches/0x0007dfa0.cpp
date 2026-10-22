#include "decls/address.h"
extern const char a_7dfa0[], b[], c[];
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
    z = FUN_001d04d0(a_7dfa0);
    x = FUN_001d04d0(b);
    y = FUN_001d04d0(c);
}
Closure2_7dfa0::Closure2_7dfa0(const char* s, int v, int w) : Method2_7dfa0(s, w) {
    extra = v;
}