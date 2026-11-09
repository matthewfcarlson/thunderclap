#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1f1050 : public ScriptFunctionFields {
  public:
    Function_1f1050(const char*, int);
    virtual void X();
};
class Method3_1f1050 : public Function_1f1050 {
  public:
    virtual void X();
    ScriptMemberFn m1c;  // 0x1c
    Method3_1f1050(const char* a, ScriptMemberFn c);
};
Method3_1f1050::Method3_1f1050(const char* a, ScriptMemberFn c) : Function_1f1050(a, 3) {
    m1c = c;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0049cad8));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
}
