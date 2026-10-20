#include "decls/address.h"
class CCameraManager;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern int g1_9ca30, g2;
class Base_9ca30 : public CtorV_001d0480 {
  public:
    Base_9ca30(void* a) : CtorV_001d0480(a, 2) { }
};
class Closure2_9ca30 : public Base_9ca30 {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char b1, b2;
    char pad2[6];
    unsigned char b3;
    char pad3[3];
    CCameraManager* mgr;
    Closure2_9ca30(void*, void*, CCameraManager*);
};
Closure2_9ca30::Closure2_9ca30(void* a, void* p, CCameraManager* m) : Base_9ca30(a) {
    mgr = m;
    b3 = FUN_001d04d0(&g1_9ca30);
    b1 = FUN_001d04d0(&g2);
    b2 = FUN_001d04d0(&g2);
}
class Closure2 : public Closure2_9ca30 {
  public:
    void* extra;
    Closure2(void*, void*, CCameraManager*);
    virtual void invoke();
};
Closure2::Closure2(void* a, void* p, CCameraManager* m) : Closure2_9ca30(a, p, m) {
    extra = p;
}