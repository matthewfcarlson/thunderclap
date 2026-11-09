#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern int VTable_2dc60;
struct Function_2dc60 {
    Function_2dc60(const char*, int);
};
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2dc60 {};
typedef void (Owner_2dc60::*Fn_2dc60)();
struct Method3_2dc60 : Function_2dc60 {
    void* vftable;
    ScriptFunctionFields f;
    Fn_2dc60 field1c;
    Method3_2dc60(const char*, Fn_2dc60);
};
Method3_2dc60::Method3_2dc60(const char* a, Fn_2dc60 x) : Function_2dc60(a, 3) {
    *(void**)this = (void*)&VTable_2dc60;
    field1c = x;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
