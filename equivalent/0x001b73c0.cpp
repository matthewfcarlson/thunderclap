// STATUS: equivalent (tools/equiv.py level 3: 20034 inputs, branch coverage 18/18)
// FUN_001b73c0 @ 0x001b73c0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Language { const char* FUN_000bb670(); };
struct Manager_1b73c0 { Language* FUN_00086280(); };
struct World { char padding[0x54]; Manager_1b73c0* manager; };
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
// MSVC 7.1 expands memcmp against a string literal inline (repe cmpsb); so does this.
static inline int memcmp_lit(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
const void* __stdcall FUN_001b73c0(const char* name) {
    if (memcmp_lit(name, "dolby", 6) == 0 || memcmp_lit(name, "radical", 8) == 0)
        return ((unsigned char*)&DAT_00434270);
    if (memcmp_lit(name + 3, "anim", 5) != 0 &&
        memcmp_lit(name, "transformation", 15) != 0 &&
        memcmp_lit(name, "dintro", 7) != 0 &&
        memcmp_lit(name, "attract", 8) != 0)
        return ((unsigned char*)&DAT_00434250);
    if (!(*(unsigned char*)&DAT_004dd839))
        return ((unsigned char*)&DAT_00434270);
    const char* language = DAT_004dd700->manager->FUN_00086280()->FUN_000bb670();
    if (memcmp_lit(language, "fr", 3) == 0)
        return ((unsigned char*)&DAT_0041dbe8);
    if (memcmp_lit(language, "it", 3) == 0)
        return ((unsigned char*)&DAT_0041dbf0);
    return ((unsigned char*)&DAT_00434270);
}