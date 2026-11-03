#include "gen/owners.h"
class Obj {
  public:
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_0035fa80() {
    ((owners::String_23fc40 *)&gObj)->FUN_0023fc40("ListenerEffectGc", (hulk_intptr)0);
    atexit(cleanup);
}