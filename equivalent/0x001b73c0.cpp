// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 17/18, incomplete; run with --inputs 12000)
// FUN_001b73c0 @ 0x001b73c0
struct Language { const char* FUN_000bb670(); };
struct Manager_1b73c0 { Language* FUN_00086280(); };
struct Root_1b73c0 { char padding[0x54]; Manager_1b73c0* manager; };
extern Root_1b73c0* DAT_004dd700;
extern unsigned char DAT_004dd839;
extern unsigned char DAT_00434250[], DAT_00434270[], DAT_0041dbe8[], DAT_0041dbf0[];
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
const void* __stdcall FUN_001b73c0(const char* name) {
    if (memcmp(name, "dolby", 6) == 0 || memcmp(name, "radical", 8) == 0)
        return DAT_00434270;
    if (memcmp(name + 3, "anim", 5) != 0 &&
        memcmp(name, "transformation", 15) != 0 &&
        memcmp(name, "dintro", 7) != 0 &&
        memcmp(name, "attract", 8) != 0)
        return DAT_00434250;
    if (!DAT_004dd839)
        return DAT_00434270;
    const char* language = DAT_004dd700->manager->FUN_00086280()->FUN_000bb670();
    if (memcmp(language, "fr", 3) == 0)
        return DAT_0041dbe8;
    if (memcmp(language, "it", 3) == 0)
        return DAT_0041dbf0;
    return DAT_00434270;
}