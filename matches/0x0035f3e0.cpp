#include "decls/data/engine/unknown.h"
// data: registry_35f3e0 = DAT_004e5df8

typedef unsigned __int64 U64_35f3e0;
extern U64_35f3e0 __cdecl make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
class Registry_35f3e0 {
  public:
    void registerPair(U64_35f3e0*, U64_35f3e0*, int, int);
};
void init() {
    U64_35f3e0 a = make("MixerMix", 0, 0);
    U64_35f3e0 b = make("Runtime_Mix", 0, 0);
    (*(Registry_35f3e0*)&DAT_004e5df8).registerPair(&b, &a, 0x38, 4);
    atexit(cleanup);
}
