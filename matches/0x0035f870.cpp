#include "decls/data/engine/audio.h"
// data: manager_35f870 = DAT_004e61a0

typedef unsigned __int64 U64_35f870;
extern U64_35f870 __cdecl FUN_002672f0(const char*, int, int);
struct Manager_35f870 {
    void FUN_002584d0(U64_35f870*, U64_35f870*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_0035f870() {
    HULK_SIZE32(AudioHalStreamPlayer, 0xd8);
    U64_35f870 first = FUN_002672f0("HalStreamPlayer", 0, 0);
    U64_35f870 second = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager_35f870*)&DAT_004e61a0).FUN_002584d0(&second, &first, (int)sizeof(AudioHalStreamPlayer), (int)__alignof(AudioHalStreamPlayer));
    atexit(cleanup);
}