// FUN_0009b930 @ 0x0009b930
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_00404d80[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Method4<Owner, void, int, int, int, int>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9b930 {};
typedef void (Owner_9b930::*Fn_9b930)(int, int, int, int);
class Method4_9b930 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9b930 fn;
    Method4_9b930* FUN_0009b930(const char*, Fn_9b930);
};
Method4_9b930* Method4_9b930::FUN_0009b930(const char* name, Fn_9b930 fp) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (void*)DAT_00404d80;
    fn = fp;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0049cad8));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0049cad8));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0049cad8));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0049cad8));
    return this;
}
