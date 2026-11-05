#include "decls/data/engine/audio.h"
// data: gThing = DAT_004e6848

class Thing {
  public:
    void FUN_0024f950();
    Thing();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003643a0();
void init() {
    ((Thing*)((char*)&DAT_004e6800 + 72))->FUN_0024f950();
    atexit(FUN_003643a0);
}