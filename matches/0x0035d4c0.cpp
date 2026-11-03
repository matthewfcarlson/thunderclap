#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: hulk_at_004dde6c = DAT_004dde6c

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00363e10();
extern "C" int atexit(void (*)(void));
class Obj {
  public:
};
void FUN_0035d4c0() {
    ((owners::String_23fc40 *)(((Obj*)((hulk_intptr)((char*)&DAT_004dde6c)))))->FUN_0023fc40(((char*)&DAT_003f3ea0), (hulk_intptr)0);
    atexit((void (*)(void))((hulk_intptr)((hulk_intptr)(void (__cdecl*)())&FUN_00363e10)));
}
