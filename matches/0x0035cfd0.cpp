#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" int atexit(void (*)(void));
extern "C" void FUN_00363ca0(void);
class Obj {
  public:
};
void __stdcall FUN_0035cfd0(void) {
    ((owners::String_23fc40 *)&((*(Obj*)&DAT_004dd738)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit((void (*)(void))FUN_00363ca0);
}
