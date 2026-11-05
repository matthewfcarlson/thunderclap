#include "decls/data/engine/audio.h"
// data: manager = DAT_004e68b0, runtimeSequence = DAT_00429270, seqCondition = DAT_00429b54

#include "compat/ptr.h"
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, hulk_intptr);
struct Manager {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003643b0();
void __cdecl FUN_0035ff30() {
    __int64 first = FUN_002672f0(((char*)&DAT_00429b54), 0, 0);
    __int64 second = FUN_002672f0(((char*)&DAT_00429270), 0, 0);
    (*(Manager*)&DAT_004e68b0).FUN_002584d0(&second, &first, 16, 4);
    atexit(FUN_003643b0);
}