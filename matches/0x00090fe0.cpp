#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1<Owner, void, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class CStatsManager {};
typedef void (CStatsManager::*Fn_90fe0)(int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_90fe0 : public Base {
  public:
    virtual void Invoke(int);
    Fn_90fe0 manager;
    Closure1_90fe0(const char*, Fn_90fe0);
};
Closure1_90fe0::Closure1_90fe0(const char* p, Fn_90fe0 m) : Base(p) {
    manager = m;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
}
class Closure1 : public Closure1_90fe0 {
  public:
    virtual void Invoke(int);
    CStatsManager* extra;
    Closure1(const char*, CStatsManager*, Fn_90fe0);
};
Closure1::Closure1(const char* p, CStatsManager* x, Fn_90fe0 m) : Closure1_90fe0(p, m) {
    extra = x;
}
