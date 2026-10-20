#include "gen/movie.h"
extern "C" int __cdecl allocate(void*, unsigned int);
struct RenderStrategyBink_nv_334910 {
    int finish();
};
extern "C" int g_value_334910;
int __cdecl target(void* p) {
    g_value_334910 = (int)p;
    movie::RenderStrategyBink* x = (movie::RenderStrategyBink*)allocate(p, 0x4c);
    if (x)
        return ((RenderStrategyBink_nv_334910*)(x))->finish();
    return 0;
}