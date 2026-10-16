// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 17/18, incomplete; run with --inputs 12000)
// FUN_001b73c0 @ 0x001b73c0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Language { const char* FUN_000bb670(); };
struct Manager_1b73c0 { Language* FUN_00086280(); };
struct World { char padding[0x54]; Manager_1b73c0* manager; };
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
const void* __stdcall FUN_001b73c0(const char* name) {
    if (memcmp(name, "dolby", 6) == 0 || memcmp(name, "radical", 8) == 0)
        return ((unsigned char*)&DAT_00434270);
    if (memcmp(name + 3, "anim", 5) != 0 &&
        memcmp(name, "transformation", 15) != 0 &&
        memcmp(name, "dintro", 7) != 0 &&
        memcmp(name, "attract", 8) != 0)
        return ((unsigned char*)&DAT_00434250);
    if (!(*(unsigned char*)&DAT_004dd839))
        return ((unsigned char*)&DAT_00434270);
    const char* language = DAT_004dd700->manager->FUN_00086280()->FUN_000bb670();
    if (memcmp(language, "fr", 3) == 0)
        return ((unsigned char*)&DAT_0041dbe8);
    if (memcmp(language, "it", 3) == 0)
        return ((unsigned char*)&DAT_0041dbf0);
    return ((unsigned char*)&DAT_00434270);
}