#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/scenario.h"
// data: hulk_at_004e1768 = DAT_004e1768

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void _atexit(void (*)());
class C {
  public:
};
void __cdecl FUN_00363fb0() throw();
void __cdecl Hook() {
    ((owners::String_23fc40 *)(((C*)((hulk_intptr)((char*)&DAT_004e1768)))))->FUN_0023fc40(((char*)&DAT_003f3ea0), (hulk_intptr)0);
    _atexit(FUN_00363fb0);
}
