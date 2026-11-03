#include "gen/owners.h"
extern "C" void __cdecl FUN_00363c80();
class G {
  public:
};
G g_obj;
void __cdecl Reg() {
    ((owners::String_23fc40 *)&g_obj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363c80);
}
