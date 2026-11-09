#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
class CTriggerVolumeManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1ffc70 : public ScriptFunctionFields {
  public:
    virtual void invoke();
    Function_1ffc70(const char*, int);
    ScriptMemberFn fn;  // 0x1c
};
class Method1 : public Function_1ffc70 {
  public:
    virtual void invoke();
    Method1(const char* s, ScriptMemberFn o) : Function_1ffc70(s, 1) {
        fn = o;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* owner;  // 0x20
    Closure1(const char* s, void* f, ScriptMemberFn o);
};
Closure1::Closure1(const char* s, void* f, ScriptMemberFn o) : Method1(s, o) {
    owner = f;
}
