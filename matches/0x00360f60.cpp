#include "decls/data/engine/audio.h"
// data: gThing = DAT_004e7620

class Thing {
  public:
    void FUN_00256c20();
    Thing();
    ~Thing();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364630();
void __cdecl FUN_00360f60() {
    ((Thing*)((char*)&DAT_004e7620))->FUN_00256c20();
    atexit(FUN_00364630);
}