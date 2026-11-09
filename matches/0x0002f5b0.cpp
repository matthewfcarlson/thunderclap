#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1<CActorManager, ...>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class CActorManager_2f5b0 {};
typedef void (CActorManager_2f5b0::*Fn_2f5b0)();
class Function_2f5b0 : public ScriptFunctionFields {
  public:
    virtual void v();
    Function_2f5b0(const char*, int);
};
class Method1 : public Function_2f5b0 {
  public:
    virtual void v();
    Fn_2f5b0 n;
    __forceinline Method1(const char* m, Fn_2f5b0 x) : Function_2f5b0(m, 1) {
        n = x;
        retType = FUN_001d04d0(&DAT_0048e0e4);
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void v();
    CActorManager_2f5b0* extra;
    Closure1(const char*, CActorManager_2f5b0*, Fn_2f5b0);
};
Closure1::Closure1(const char* mgr, CActorManager_2f5b0* n, Fn_2f5b0 x) : Method1(mgr, x) {
    extra = n;
}
