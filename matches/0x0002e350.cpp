#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_003f432c[];
class Function_2e350 {
  public:
    void Init(const char*, int);
};
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2e350 {};
typedef void (Owner_2e350::*Fn_2e350)();
class Method3 : public Function_2e350 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_2e350 m1c;
    Method3(const char*, Fn_2e350);
};
extern const char s2_2e350[];
extern const char DAT_0048e10c[];
Method3::Method3(const char* a, Fn_2e350 x) {
    Init(a, 3);
    v = (void*)DAT_003f432c;
    m1c = x;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(DAT_0048e10c);
    f.argTypes[2] = FUN_001d04d0(DAT_0048e10c);
}
