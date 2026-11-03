#include "decls/data/game/global.h"
// data: hulk_at_004e222d = DAT_004e222d

#include "compat/ptr.h"
#include "gen/owners.h"
extern void* g_obj;
extern int atexit(void (*fn)());
extern "C" void FUN_00364020();
class G {
  public:
};
void __cdecl FUN_0035e6e0() {
    ((owners::String_23fc40 *)(((G*)((hulk_intptr)(((char*)&DAT_004e222d) + 0x3)))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364020);
}
