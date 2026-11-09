#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: a_cfef0 = DAT_0048e100
// Closure2<HUDOverlay, void, int, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class HUDOverlay {};
typedef void (HUDOverlay::*Fn_cfef0)(int, bool);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base_cfef0 : public CtorV_001d0480 {
  public:
    Base_cfef0(const char* n) : CtorV_001d0480(n, 2) { }
};
class Closure2_cfef0 : public Base_cfef0 {
  public:
    virtual void f();
    Fn_cfef0 arg;
    Closure2_cfef0(const char*, Fn_cfef0);
};
Closure2_cfef0::Closure2_cfef0(const char* n, Fn_cfef0 v) : Base_cfef0(n) {
    arg = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
class Closure2 : public Closure2_cfef0 {
  public:
    HUDOverlay* val;
    Closure2(const char*, HUDOverlay*, Fn_cfef0);
};
Closure2::Closure2(const char* n, HUDOverlay* v, Fn_cfef0 w) : Closure2_cfef0(n, w) {
    val = v;
}
