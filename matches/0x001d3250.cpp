#include "decls/data/game/global.h"
// data: text0f0 = DAT_0048e0f0, text100 = DAT_0048e100

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_00422654[];
// Method4<ScriptHandler, void, const char* x4>'s initializer (name, member function), inlined by 0x001d46d0:
// Function's fields (include/decls/data/script.h), then the member-function pointer; returns this.
class ScriptHandler_1d3250 {};
typedef void (ScriptHandler_1d3250::*Fn_1d3250)(const char*, const char*, const char*, const char*);
class Method4_1d3250 {
  public:
    void* vft;
    ScriptFunctionFields f;
    Fn_1d3250 fn;
    void FUN_001d0480(const char*, int);  // Function::Function(name, argc)
    Method4_1d3250* FUN_001d3250(const char*, Fn_1d3250);
};
Method4_1d3250* Method4_1d3250::FUN_001d3250(const char* a, Fn_1d3250 b) {
    FUN_001d0480(a, 4);
    vft = (void*)DAT_00422654;
    fn = b;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    return this;
}
