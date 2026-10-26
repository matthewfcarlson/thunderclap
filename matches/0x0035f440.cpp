#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
// data: mixerName = DAT_004290f8, registry = DAT_004e5e40, runtimeName = DAT_004290d8

extern "C" __int64 __cdecl Lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
class Registry {
  public:
    void Init(const __int64*, const __int64*, int, int);
};
void __cdecl FUN_0035f440() {
    __int64 mixer = Lookup(DAT_004290f8, 0, 0);
    __int64 runtime = Lookup(DAT_004290d8, 0, 0);
    (*(Registry*)((char*)&DAT_004e5df8 + 72)).Init(&runtime, &mixer, 28, 4);
    atexit(Cleanup);
}