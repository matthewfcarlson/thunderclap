#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e6d98

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364480();
void __cdecl target() {
    HULK_SIZE32(AudioChannelVolumeFadeBehaviour, 0x24);
    U64 a = FUN_002672f0("ChannelVolumeFadeBehaviour", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6d98).FUN_002584d0(&b, &a, (int)sizeof(AudioChannelVolumeFadeBehaviour), (int)__alignof(AudioChannelVolumeFadeBehaviour));
    atexit(FUN_00364480);
}