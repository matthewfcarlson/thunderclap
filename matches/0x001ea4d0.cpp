#include "decls/address.h"
#include "decls/data/game/global.h"
class Function_1ea4d0 {
  public:
    Function_1ea4d0(int, int);
    virtual void run();
};
class Method1 : public Function_1ea4d0 {
  public:
    int a[3];
    unsigned char b;
    char pad[7];
    unsigned char c;
    char pad2[3];
    int value;
    Method1(int x, int v) : Function_1ea4d0(x, 1), value(v) {
        c = FUN_001d04d0(((int*)&DAT_0048e100));
        b = FUN_001d04d0(((int*)&DAT_0048e134));
    }
    virtual void run();
};
class Closure1 : public Method1 {
  public:
    int other;
    Closure1(int x, int y, int z);
    virtual void run();
};
Closure1::Closure1(int x, int y, int z) : Method1(x, z), other(y) {}