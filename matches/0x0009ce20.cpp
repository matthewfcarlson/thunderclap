#include "decls/address.h"
extern int a_9ce20, b, c;
class Function_9ce20 {
  public:
    Function_9ce20(int, int) throw();
    virtual void f();
    char pad[12];
    char x;
    char y;
    char pad2[6];
    char z;
    char pad3[3];
    int p;
};
class Method2 : public Function_9ce20 {
  public:
    Method2(int arg1, int arg3) throw() : Function_9ce20(arg1, 2) {
        p = arg3;
        z = FUN_001d04d0(&a_9ce20);
        x = FUN_001d04d0(&b);
        y = FUN_001d04d0(&c);
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(int, int, int) throw();
    virtual void f();
    int q;
};
Closure2::Closure2(int arg1, int arg2, int arg3) throw() : Method2(arg1, arg3) {
    q = arg2;
}