#include "decls/data/game/global.h"
// data: g_hash_35d3a0 = DAT_004ddc00, g_size_35d3a0 = DAT_004ddc04, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Hash_35d3a0 {
    void* p;
    unsigned int s;
};
extern "C" Hash_35d3a0 __cdecl FUN_0027b020(void*);
void __cdecl FUN_0035d3a0() {
    Hash_35d3a0 h = FUN_0027b020((void*)((hulk_intptr)((char*)&DAT_0040048c)));
    (*(void**)&DAT_004ddc00) = h.p;
    (*(unsigned int*)&DAT_004ddc04) = h.s;
}
