#include "decls/data/engine/audio.h"
// data: gManager = DAT_004e7898

extern "C" __int64 __cdecl Hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
class Manager {
  public:
    void Init(__int64*, __int64*, int, int);
};
void __cdecl Target() {
    __int64 a = Hash("HalBuffer", 0, 0);
    __int64 b = Hash("Runtime_Hal", 0, 0);
    (*(Manager*)&DAT_004e7898).Init(&b, &a, 0x28, 4);
    atexit(Cleanup);
}