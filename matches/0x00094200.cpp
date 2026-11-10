#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
extern "C" char DAT_004046dc[];
// Method3<Owner, void, int, int, bool>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_94200 {};
typedef void (Owner_94200::*Fn_94200)(int, int, bool);
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
extern char __cdecl Query(const char*);
class Method3_94200 : public FUN_001d0480 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_94200 value;
    Method3_94200(const char* a, Fn_94200 b);
};
Method3_94200::Method3_94200(const char* a, Fn_94200 b) : FUN_001d0480(a, 3) {
    v = (void*)DAT_004046dc;
    value = b;
    f.retType = Query(((char*)&DAT_0048e100));
    f.argTypes[0] = Query(((char*)&DAT_0048e134));
    f.argTypes[1] = Query(((char*)&DAT_0048e134));
    f.argTypes[2] = Query(&DAT_0048e0e4);
}
