#include "decls/data/game/hulkfight.h"
// data: g_thing = DAT_004dd2d0
#include "gen/owners.h"

extern "C" void _atexit(void (*)(void));
class Thing {
  public:
};
extern "C" void __cdecl FUN_00363c70(void);
void __cdecl FUN_0035cf70(void) {
    ((owners::String_23fc40 *)&((*(Thing*)&DAT_004dd2d0)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363c70);
}
