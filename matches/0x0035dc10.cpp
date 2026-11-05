#include "gen/owners.h"
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363e50();
class Obj {
  public:
};
extern Obj gObj;
void initSound() {
    ((owners::String_23fc40 *)&gObj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363e50);
}