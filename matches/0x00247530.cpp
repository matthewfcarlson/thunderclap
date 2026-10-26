#include "decls/data/engine/audio.h"

struct V {
    void* a;
    int(__cdecl* b)(void*, int);
};
int target(int x) {
    return (*(V**)&DAT_004cc1fc)->b((*(V**)&DAT_004cc1fc), x);
}
