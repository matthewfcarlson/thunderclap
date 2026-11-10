#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
extern const int Function4_vftable;
class Function4 : public FUN_001d0480 {
  public:
    hulk_intptr vf;
    ScriptFunctionFields f;
    ScriptMemberFn fn;
    Function4(const char*, ScriptMemberFn);
};
Function4::Function4(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 4) {
    vf = (hulk_intptr)&Function4_vftable;
    fn = b;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
}
