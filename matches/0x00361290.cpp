#include "decls/data/engine/audio.h"
// data: gHolder = DAT_004e78e0

extern "C" __int64 __cdecl hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Holder {
  public:
    void Set(__int64*, __int64*, int, int);
};
void target() {
    __int64 a = hash("SeqTrackPlayer", 0, 0);
    __int64 b = hash("Runtime_Sequence", 0, 0);
    (*(Holder*)&DAT_004e78e0).Set(&b, &a, 0x60, 4);
    atexit(cleanup);
}
