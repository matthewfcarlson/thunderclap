#include "gen/owners.h"
extern "C" int __cdecl _atexit(void (*)());
struct Sound {
};
Sound gSound;
void FUN_00363e40() {}
void Init() {
    ((owners::String_23fc40 *)&gSound)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363e40);
}
