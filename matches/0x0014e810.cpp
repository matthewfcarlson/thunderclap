#include "compat/ptr.h"
class Condition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class Param {
  public:
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
};
namespace hulkfight { namespace motion { class CollisionSourceIsMissileCondition : public Condition, public Param {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int, void*, int);
    char pad[4];
    unsigned char value;
}; }}
extern int helper(void*, int, void*, void*, int);
extern int typeA_14e810;
extern int typeB_14e810;
struct Source_14e810 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int get();
};
bool hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_6(int, void* p, int) {
    if (helper(p, 0, &typeA_14e810, &typeB_14e810, 0) == 0)
        return false;
    hulk_intptr x = ((Source_14e810*)p)->get();
    if (!x)
        return false;
    return *(unsigned char*)(x + 0x14) == value;
}