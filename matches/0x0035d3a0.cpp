#include "decls/data/game/global.h"
// data: g_hash_35d3a0 = DAT_004ddc00, g_size_35d3a0 = DAT_004ddc04, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Hash_35d3a0 {
    void* p;
    unsigned int s;
};
unsigned __int64 FUN_0027b020(const char* s);
void __cdecl FUN_0035d3a0() {
    unsigned __int64 h = FUN_0027b020((const char*)((char*)&DAT_0040048c));
    (*(unsigned int*)&DAT_004ddc00) = (unsigned int)h;
    (*(unsigned int*)&DAT_004ddc04) = (unsigned int)(h >> 32);
}
