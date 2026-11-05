#include "gen/owners.h"
#include "decls/data/engine/audio.h"
// data: gName = DAT_004e61f0

class Name {
  public:
    Name(const char*, int);
    ~Name();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364270();
void init() {
    ((owners::String_23fc40 *)&DAT_004e61f0)->FUN_0023fc40("?Name?", (hulk_intptr)0);
    atexit(FUN_00364270);
}