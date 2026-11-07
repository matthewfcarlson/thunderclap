#include "decls/data/engine/audio.h"
// data: gRegistry_361170 = DAT_004e7808

extern "C" __int64 FUN_002672f0(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364690();
class Registry_361170 {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void Init() {
    HULK_SIZE32(AudioOmHalStream, 0x1c8);
    __int64 a = FUN_002672f0("OmHalStream", 0, 0);
    __int64 b = FUN_002672f0("Transient", 0, 0);
    (*(Registry_361170*)&DAT_004e7808).FUN_002584d0(&b, &a, (int)sizeof(AudioOmHalStream), (int)__alignof(AudioOmHalStream));
    atexit(FUN_00364690);
}