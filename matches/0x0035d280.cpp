#include "gen/owners.h"
extern "C" void __cdecl FUN_00363d00();
extern "C" int atexit(void (*)(void));
struct G {
    void Init(const char*, int);
};
extern G g;
void Init() {
    ((owners::String_23fc40 *)&g)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363d00);
}
