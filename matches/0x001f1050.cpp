#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class Function_1f1050 {
  public:
    Function_1f1050(int, int);
    virtual void X();
    char pad[0xc];
};
class Method3_1f1050 : public Function_1f1050 {
  public:
    virtual void X();
    char b10, b11, b12, pad2[5];
    char b18;
    char pad3[3];
    int m1c;
    Method3_1f1050(int a, int c);
};
Method3_1f1050::Method3_1f1050(int a, int c) : Function_1f1050(a, 3) {
    m1c = c;
    b18 = FUN_001d04d0(((char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((char*)&DAT_0049cad8));
    b11 = FUN_001d04d0(((char*)&DAT_0048e128));
    b12 = FUN_001d04d0(((char*)&DAT_0048e128));
}
