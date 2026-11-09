#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
class CWorldCollisionManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2030c0 : public CtorV_001d0480 {
  public:
    Function_2030c0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_2030c0 {
  public:
    virtual void Invoke();
    ScriptMemberFn fn;  // 0x1c
    Method1(const char* s, ScriptMemberFn o) : Function_2030c0(s) {
        fn = o;
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke();
    CWorldCollisionManager* owner;  // 0x20
    Closure1(const char*, CWorldCollisionManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* s, CWorldCollisionManager* d, ScriptMemberFn o) : Method1(s, o) {
    owner = d;
}
