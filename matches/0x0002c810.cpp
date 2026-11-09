#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
extern "C" char DAT_003f408c[];
typedef unsigned char u8;
struct ThisCall_001d0480 {
    void setup(const char*, int);
};
u8 __cdecl getval(const void*);
// Method3's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_2c810 {};
typedef void (Owner_2c810::*Fn_2c810)();
class Method3 {
  public:
    void* vf;
    ScriptFunctionFields f;
    Fn_2c810 value;
    Method3* target(const char*, Fn_2c810);
};
Method3* Method3::target(const char* a, Fn_2c810 c) {
    ((ThisCall_001d0480*)(this))->setup(a, 3);
    vf = (void*)DAT_003f408c;
    value = c;
    f.retType = getval(((char*)&DAT_0048e100));
    f.argTypes[0] = getval(((char*)&DAT_0048e0f0));
    f.argTypes[1] = getval(((char*)&DAT_0048e128));
    f.argTypes[2] = getval(((char*)&DAT_0048e0e4));
    return this;
}
