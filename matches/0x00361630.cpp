#include "decls/data/engine/audio.h"
// data: gRegistry_361630 = DAT_004e7b50

typedef unsigned __int64 U64_361630;
extern U64_361630 __cdecl Find(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
class Registry_361630 {
  public:
    void Add(U64_361630*, U64_361630*, int, int);
};
void __cdecl FUN_00361630() {
    U64_361630 a = Find("HalRsdFileHeader", 0, 0);
    U64_361630 b = Find("Runtime_Hal", 0, 0);
    (*(Registry_361630*)((char*)&DAT_004e7b08 + 72)).Add(&b, &a, 0x1a4, 4);
    atexit(Cleanup);
}