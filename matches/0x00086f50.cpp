#include "decls/address.h"
extern const char g[];
class Base {
  public:
    virtual void f();
    Base(const char*, int);
};
class Function2 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int d;
    Function2(const char*, int);
};
Function2::Function2(const char* s, int v) : Base(s, 2) {
    d = v;
    c = FUN_001d04d0(g);
    a = FUN_001d04d0(g);
    b = FUN_001d04d0(g);
}