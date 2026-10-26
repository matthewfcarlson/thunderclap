#include "decls/data/engine/audio.h"

typedef int(__cdecl* Fn_247550)(void*, int, int);
struct T_247550 {
    void* x;
    void* y;
    Fn_247550 f;
};
int target(int a, int b) {
    return (*(T_247550**)&DAT_004cc1fc)->f((*(T_247550**)&DAT_004cc1fc), a, b);
}