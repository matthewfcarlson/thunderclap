#include "decls/data/engine/unknown.h"
// data: registry_35f3e0 = DAT_004e5df8

typedef unsigned __int64 U64_35f3e0;
extern U64_35f3e0 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364170();
class Registry_35f3e0 {
  public:
    void FUN_002584d0(U64_35f3e0*, U64_35f3e0*, int, int);
};
void init() {
    HULK_SIZE32(AudioMixerMix, 0x38);
    U64_35f3e0 a = FUN_002672f0("MixerMix", 0, 0);
    U64_35f3e0 b = FUN_002672f0("Runtime_Mix", 0, 0);
    (*(Registry_35f3e0*)&DAT_004e5df8).FUN_002584d0(&b, &a, (int)sizeof(AudioMixerMix), (int)__alignof(AudioMixerMix));
    atexit(FUN_00364170);
}
