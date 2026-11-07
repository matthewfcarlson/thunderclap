#include "decls/data/engine/audio.h"
// data: registry = DAT_004e6110

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364230();
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
void __cdecl FUN_0035f760() {
    HULK_SIZE32(AudioChannelVolumeArray, 0x40);
    U64 x = FUN_002672f0("ChannelVolumeArray", 0, 0);
    U64 y = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6110).FUN_002584d0(&y, &x, (int)sizeof(AudioChannelVolumeArray), (int)__alignof(AudioChannelVolumeArray));
    atexit(FUN_00364230);
}