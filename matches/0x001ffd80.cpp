#include "decls/data/game/global.h"
#include "decls/data/script.h"

// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Get(const char*);
class InitBase : public CtorV_001d0480 {
  public:
    InitBase(const char* name) : CtorV_001d0480(name, 1) { }
};
class Closure1_1ffd80 : public InitBase {
  public:
    virtual void f();
    ScriptMemberFn z;  // 0x1c
    Closure1_1ffd80(const char*, ScriptMemberFn);
};
Closure1_1ffd80::Closure1_1ffd80(const char* name, ScriptMemberFn v) : InitBase(name) {
    z = v;
    retType = Get(((const char*)&DAT_0048e0f0));
    argTypes[0] = Get(((const char*)&DAT_0048e134));
}
class Closure1 : public Closure1_1ffd80 {
  public:
    virtual void f();
    void* val;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* name, void* v, ScriptMemberFn w) : Closure1_1ffd80(name, w) {
    val = v;
}
