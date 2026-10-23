#include "decls/address.h"
extern char DAT_004c55f0;
extern char DAT_0048e134;
class Function_1ce860 {
  public:
    Function_1ce860(int, int);
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
};
class Method1 : public Function_1ce860 {
  public:
    Method1(int x, int y) : Function_1ce860(x, 1) {
        c = y;
        b = FUN_001d04d0(&DAT_004c55f0);
        a = FUN_001d04d0(&DAT_0048e134);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int x, int y, int z);
    virtual void f();
    int d;
};
Closure1::Closure1(int x, int y, int z) : Method1(x, z) {
    d = y;
}