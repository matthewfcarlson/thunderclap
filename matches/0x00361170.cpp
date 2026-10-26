#include "decls/data/engine/audio.h"
// data: gRegistry_361170 = DAT_004e7808

extern "C" __int64 Parse(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
void __cdecl Cleanup();
class Registry_361170 {
  public:
    void Register(__int64*, __int64*, int, int);
};
void Init() {
    __int64 a = Parse("OmHalStream", 0, 0);
    __int64 b = Parse("Transient", 0, 0);
    (*(Registry_361170*)&DAT_004e7808).Register(&b, &a, 0x1c8, 4);
    atexit(Cleanup);
}