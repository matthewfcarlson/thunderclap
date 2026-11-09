#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
typedef unsigned char byte;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char*);
};
Base::Base(const char* x) : CtorV_001d0480(x, 1) {
}
class Closure1_205c00 : public Base {
  public:
    virtual void invoke();
    ScriptMemberFn obj;  // 0x1c
    Closure1_205c00(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_205c00 {
  public:
    virtual void invoke();
    void* val;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1_205c00::Closure1_205c00(const char* x, ScriptMemberFn y) : Base(x) {
    obj = y;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
}
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Closure1_205c00(x, z) {
    val = y;
}
