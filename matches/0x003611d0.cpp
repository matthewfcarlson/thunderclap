#include "decls/data/engine/audio.h"
// data: globalObj_3611d0 = DAT_004e7850

#include "compat/ptr.h"
extern "C" unsigned __int64 __cdecl make(const char*, int, hulk_intptr);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Obj_3611d0 {
  public:
    void Init(unsigned __int64*, unsigned __int64*, int, int);
};
void target() {
    unsigned __int64 a = make("OmHalStream Temp Aligned Stream Mem", 0, 0);
    unsigned __int64 b = make("Temp", 0, 0);
    (*(Obj_3611d0*)((char*)&DAT_004e7808 + 72)).Init(&b, &a, 0x4000, 0x80);
    atexit(cleanup);
}