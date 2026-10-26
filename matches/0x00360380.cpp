#include "decls/data/engine/audio.h"
// data: globalManager = DAT_004e6c30, nameA = DAT_00429e44, nameB = DAT_00429270

typedef __int64 I64;
extern I64 __cdecl make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager {
    void setup(I64*, I64*, int, int);
};
void __cdecl FUN_00360380() {
    I64 a = make(DAT_00429e44, 0, 0);
    I64 b = make(DAT_00429270, 0, 0);
    (*(Manager*)((char*)&DAT_004e6bc8 + 104)).setup(&b, &a, 16, 4);
    atexit(cleanup);
}