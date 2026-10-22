#include "decls/address.h"
class CActorManager;
class Function_2f5b0 {
  public:
    virtual void v();
    char pad[12];
    Function_2f5b0(CActorManager*, int);
};
extern char g1, g2;
class Method1 : public Function_2f5b0 {
  public:
    virtual void v();
    char flag1;
    char pad1[7];
    char flag2;
    char pad2[3];
    int n;
    __forceinline Method1(CActorManager* m, int x) : Function_2f5b0(m, 1) {
        n = x;
        flag2 = FUN_001d04d0(&g1);
        flag1 = FUN_001d04d0(&g2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void v();
    int extra;
    Closure1(CActorManager*, int, int);
};
Closure1::Closure1(CActorManager* mgr, int n, int x) : Method1(mgr, x) {
    extra = n;
}
