#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

struct V {
    void* a;
    int(__cdecl* b)(void*, int);
};
extern "C" hulk_intptr FUN_00247530(hulk_intptr x) {
    return (*(V**)&DAT_004cc1fc)->b((*(V**)&DAT_004cc1fc), x);
}
