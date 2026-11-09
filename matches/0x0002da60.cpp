#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_003f424c[];
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2da60 {};
typedef void (Owner_2da60::*Fn_2da60)();
class Method3_2da60 {
  public:
    void* vf;
    ScriptFunctionFields f;
    Fn_2da60 m1c;
    void Init(const char*, int);
    Method3_2da60(const char*, Fn_2da60);
};
Method3_2da60::Method3_2da60(const char* p, Fn_2da60 x) {
    Init(p, 3);
    vf = (void*)DAT_003f424c;
    m1c = x;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
