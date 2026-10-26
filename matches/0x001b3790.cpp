#include "decls/data/game/global.h"

struct Vector {
    float x, y, z;
};
extern int c;
unsigned char __cdecl lookup(const void*);
class Function_1b3790 {
  public:
    virtual void f();
    Function_1b3790(int, int);
    char pad[12];
};
class Function2 : public Function_1b3790 {
  public:
    virtual void f();
    Function2(int, int);
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int val;
};
Function2::Function2(int arg, int v) : Function_1b3790(arg, 2) {
    val = v;
    z = lookup(((int*)&DAT_0048e100));
    x = lookup(((int*)&DAT_0048e134));
    y = lookup(&c);
}