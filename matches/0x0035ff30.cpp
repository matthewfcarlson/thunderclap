#include "decls/data/engine/audio.h"
// data: manager = DAT_004e68b0, runtimeSequence = DAT_00429270, seqCondition = DAT_00429b54

#include "compat/ptr.h"
extern "C" __int64 __cdecl make(const char*, int, hulk_intptr);
struct Manager {
    void init(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_0035ff30() {
    __int64 first = make(((char*)&DAT_00429b54), 0, 0);
    __int64 second = make(((char*)&DAT_00429270), 0, 0);
    (*(Manager*)&DAT_004e68b0).init(&second, &first, 16, 4);
    atexit(cleanup);
}