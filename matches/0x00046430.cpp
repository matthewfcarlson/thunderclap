#include "decls/address.h"
#include "decls/data/game/global.h"
class Base {
  public:
    virtual void f();
    Base(const char*, int);
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
};
class Closure1_46430 : public Base {
  public:
    Closure1_46430(const char*, int);
    virtual void f();
};
Closure1_46430::Closure1_46430(const char* s, int x) : Base(s, 1) {
    c = x;
    b = FUN_001d04d0(((char*)&DAT_0048e100));
    a = FUN_001d04d0(((char*)&DAT_0048e0f0));
}
class Closure1 : public Closure1_46430 {
  public:
    int d;
    Closure1(const char*, int, int);
    virtual void f();
};
Closure1::Closure1(const char* s, int x, int y) : Closure1_46430(s, y) {
    d = x;
}
