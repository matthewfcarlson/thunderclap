#include "decls/data/engine/audio.h"
// data: global = DAT_004e7570

extern "C" __int64 __cdecl get(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Global {
  public:
    void init(__int64*, __int64*, int, int);
};
void __cdecl FUN_00360e90() {
    __int64 a = get("SeqActionClip", 0, 0);
    __int64 b = get("Runtime_Sequence", 0, 0);
    (*(Global*)((char*)&DAT_004e7508 + 104)).init(&b, &a, 0x1c, 4);
    atexit(cleanup);
}