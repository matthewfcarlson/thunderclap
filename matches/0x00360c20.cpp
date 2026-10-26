#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e7360

typedef unsigned __int64 U64;
extern U64 __cdecl Hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
struct Registry {
    void Register(U64*, U64*, int, int);
};
void Init() {
    U64 a = Hash("SeqCommandLogicRepeat", 0, 0);
    U64 b = Hash("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e72f8 + 104)).Register(&b, &a, 24, 4);
    atexit(Cleanup);
}