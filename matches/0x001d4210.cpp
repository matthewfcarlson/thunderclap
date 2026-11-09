#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
extern "C" char DAT_00422644[];
extern "C" char DAT_00422800[];
// Closure1<ScriptHandler, const char*, const char*>'s initializer (name, object, member function), inlined by
// 0x001d4660: Function's fields (include/decls/data/script.h), then Method1's member-function pointer and Closure1's
// object; returns this.
class ScriptHandler_1d4210 {};
typedef const char* (ScriptHandler_1d4210::*Fn_1d4210)(const char*);
class Closure1_1d4210 : public ScriptFunctionFields {
  public:
    virtual void V();
    void Init(const char*, int);
    Fn_1d4210 fn;
    ScriptHandler_1d4210* owner;
    Closure1_1d4210* Run(const char*, ScriptHandler_1d4210*, Fn_1d4210);
};
Closure1_1d4210* Closure1_1d4210::Run(const char* a, ScriptHandler_1d4210* b, Fn_1d4210 c) {
    Init(a, 1);
    *(void**)this = (void*)DAT_00422644;
    fn = c;
    retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    *(void**)this = (void*)DAT_00422800;
    owner = b;
    return this;
}
