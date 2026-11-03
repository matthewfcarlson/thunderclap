#include "decls/data/game/global.h"
// data: hulk_at_004ddf9c = DAT_004ddf9c

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" int atexit(void (*)());
struct Module {
};
void Cleanup() {}
void FUN_0035d7a0() {
    Module* m = (Module*)((hulk_intptr)((char*)&DAT_004ddf9c));
    ((void *)((owners::String_23fc40 *)m)->FUN_0023fc40("sound/rsd", (hulk_intptr)0));
    atexit(Cleanup);
}
