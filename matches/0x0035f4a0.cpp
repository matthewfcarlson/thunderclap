#include "decls/data/engine/unknown.h"
// data: globalObj = DAT_004e5e88

typedef unsigned __int64 U64;
extern "C" U64 __cdecl get(const char*, int, int);
struct Obj {
    void set(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void init() {
    U64 a = get("MixerBuss", 0, 0);
    U64 b = get("Runtime_Mix", 0, 0);
    (*(Obj*)&DAT_004e5e88).set(&b, &a, 0x28, 4);
    atexit(cleanup);
}