#include "decls/data/engine/audio.h"
// data: manager_35f7c0 = DAT_004e6158

typedef unsigned __int64 U64_35f7c0;
extern "C" U64_35f7c0 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364240();
class Manager_35f7c0 {
  public:
    void FUN_002584d0(U64_35f7c0*, U64_35f7c0*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(AudioChannelSendVolumeArray, 0x100);
    U64_35f7c0 a = FUN_002672f0("ChannelSendVolumeArray", 0, 0);
    U64_35f7c0 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Manager_35f7c0*)((char*)&DAT_004e6158)).FUN_002584d0(&b, &a, (int)sizeof(AudioChannelSendVolumeArray), (int)__alignof(AudioChannelSendVolumeArray));
    atexit(FUN_00364240);
}