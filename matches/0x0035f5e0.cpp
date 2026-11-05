#include "decls/data/engine/audio.h"
// data: sequenceName = DAT_00429270, trackName = DAT_00429290

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern Registry registry;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_0035f5e0() {
    __int64 track = FUN_002672f0(((char*)&DAT_00429290), 0, 0);
    __int64 sequence = FUN_002672f0(((char*)&DAT_00429270), 0, 0);
    registry.FUN_002584d0(&sequence, &track, 0x20, 4);
    atexit(cleanup);
}