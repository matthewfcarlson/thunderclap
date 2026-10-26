#include "decls/data/engine/core.h"
// data: g_value_334910 = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/movie.h"
extern "C" hulk_intptr __cdecl allocate(void*, unsigned int);
struct RenderStrategyBink_nv_334910 {
    int finish();
};
int __cdecl target(void* p) {
    DAT_004cdbb0 = (hulk_intptr)p;
    movie::RenderStrategyBink* x = (movie::RenderStrategyBink*)allocate(p, 0x4c);
    if (x)
        return ((RenderStrategyBink_nv_334910*)(((movie::RenderStrategyBink*)(x))))->finish();
    return 0;
}