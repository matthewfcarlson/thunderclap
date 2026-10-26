#include "decls/data/engine/audio.h"
// data: beat = DAT_0042ab20, global = DAT_004e7a30, sequence = DAT_0042a620

extern "C" __int64 __cdecl lookup(const char*, int, int);
class Object {
  public:
    void init(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl target() {
    __int64 a = lookup(DAT_0042ab20, 0, 0);
    __int64 b = lookup(DAT_0042a620, 0, 0);
    (*(Object*)((char*)&DAT_004e7a2c + 4)).init(&b, &a, 8, 4);
    atexit(cleanup);
}