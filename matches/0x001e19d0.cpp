#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
class CSPManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1e19d0 : public Base {
  public:
    virtual void invoke(float);
    ScriptMemberFn obj;  // 0x1c
    Closure1_1e19d0(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1e19d0 {
  public:
    virtual void invoke(float);
    void* data;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1_1e19d0::Closure1_1e19d0(const char* p, ScriptMemberFn f) : Base(p) {
    obj = f;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
Closure1::Closure1(const char* p, void* f, ScriptMemberFn q) : Closure1_1e19d0(p, q) {
    data = f;
}
