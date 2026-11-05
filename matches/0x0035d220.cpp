#include "gen/owners.h"
#include "decls/data/game/hulkfight.h"

class T {
  public:
    T(const char*, int);
    ~T();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363cf0();
void f() {
    ((owners::String_23fc40 *)&DAT_004dd9d0)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363cf0);
}