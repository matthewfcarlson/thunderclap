#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
struct Hash_35d3a0 {
    void* p;
    unsigned int s;
};
extern "C" Hash_35d3a0 __cdecl FUN_0027b020(void*);
extern "C" void* g_hash_35d3a0;
extern "C" unsigned int g_size_35d3a0;
void __cdecl FUN_0035d3a0() {
    Hash_35d3a0 h = FUN_0027b020((void*)((hulk_intptr)hulk_at_0040048c));
    g_hash_35d3a0 = h.p;
    g_size_35d3a0 = h.s;
}
