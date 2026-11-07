#include "decls/data/engine/audio.h"
// data: globalManager = DAT_004e6c30, nameA = DAT_00429e44, nameB = DAT_00429270

typedef __int64 I64;
extern I64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364450();
struct Manager {
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_00360380() {
    HULK_SIZE32(AudioSeqActionPlayTrack, 0x10);
    I64 a = FUN_002672f0(DAT_00429e44, 0, 0);
    I64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Manager*)((char*)&DAT_004e6c30)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionPlayTrack), (int)__alignof(AudioSeqActionPlayTrack));
    atexit(FUN_00364450);
}