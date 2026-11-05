#include "decls/data/game/global.h"

class CStaticAllocator_35e6b0 {
  public:
    void FUN_0008fde0(int, int, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364010();
void __cdecl FUN_0035e6b0() {
    (*(CStaticAllocator_35e6b0*)&DAT_004e2210).FUN_0008fde0(0x100, 0x20, 0xd, 0);
    atexit(FUN_00364010);
}