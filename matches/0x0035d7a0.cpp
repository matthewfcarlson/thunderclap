#include "decls/data/game/global.h"
// data: hulk_at_004ddf9c = DAT_004ddf9c

#include "compat/ptr.h"
extern "C" int atexit(void (*)());
struct Module {
    void* Register(const char* name, int n);
};
void Cleanup() {}
void FUN_0035d7a0() {
    Module* m = (Module*)((hulk_intptr)((char*)&DAT_004ddf9c));
    m->Register("sound/rsd", 0);
    atexit(Cleanup);
}
