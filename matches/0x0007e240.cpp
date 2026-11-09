#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1<CAmbientsManager, void, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class CAmbientsManager_7e240 {};
typedef void (CAmbientsManager_7e240::*Fn_7e240)(float);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_7e240 : public CtorV_001d0480 {
  public:
    Function_7e240(const char* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Function_7e240 {
  public:
    virtual void Invoke(float);
    Fn_7e240 obj;
    Method1(const char* x, Fn_7e240 z) : Function_7e240(x) {
        obj = z;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    CAmbientsManager_7e240* extra;
    Closure1(const char*, CAmbientsManager_7e240*, Fn_7e240);
};
Closure1::Closure1(const char* x, CAmbientsManager_7e240* y, Fn_7e240 z) : Method1(x, z) {
    extra = y;
}
