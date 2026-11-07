#include "decls/data/engine/audio.h"
// data: registry = DAT_004e67b8

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_00364370();
void __cdecl target() {
    HULK_SIZE32(AudioChannelSendVolumeFadeBehaviour, 0x24);
    U64 a = FUN_002672f0("ChannelSendVolumeFadeBehaviour", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e67b8).FUN_002584d0(&b, &a, (int)sizeof(AudioChannelSendVolumeFadeBehaviour), (int)__alignof(AudioChannelSendVolumeFadeBehaviour));
    atexit(FUN_00364370);
}