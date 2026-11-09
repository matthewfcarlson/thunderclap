#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure2<CCameraManager, void, A1, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class CCameraManager {};
typedef void (CCameraManager::*Fn_9ca30)(int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern int g2;
class Base_9ca30 : public CtorV_001d0480 {
  public:
    Base_9ca30(const char* a) : CtorV_001d0480(a, 2) { }
};
class Closure2_9ca30 : public Base_9ca30 {
  public:
    virtual void invoke();
    Fn_9ca30 mgr;
    Closure2_9ca30(const char*, CCameraManager*, Fn_9ca30);
};
Closure2_9ca30::Closure2_9ca30(const char* a, CCameraManager* p, Fn_9ca30 m) : Base_9ca30(a) {
    mgr = m;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(&g2);
    argTypes[1] = FUN_001d04d0(&g2);
}
class Closure2 : public Closure2_9ca30 {
  public:
    CCameraManager* extra;
    Closure2(const char*, CCameraManager*, Fn_9ca30);
    virtual void invoke();
};
Closure2::Closure2(const char* a, CCameraManager* p, Fn_9ca30 m) : Closure2_9ca30(a, p, m) {
    extra = p;
}
