#include "decls/data/game/global.h"

extern "C" unsigned char probe(const char*);
class Function_1ba410 {
  public:
    Function_1ba410(int, int);
    virtual void f();
    char pad[0x1c - 4];
};
class Method1 : public Function_1ba410 {
  public:
    int x;
    Method1(int a, int c) : Function_1ba410(a, 1), x(c) {
        *((unsigned char*)this + 0x18) = probe(((const char*)&DAT_0048e100));
        *((unsigned char*)this + 0x10) = probe(((const char*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    int y;
    Closure1(int a, int b, int c);
    virtual void f();
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c), y(b) {}
