#include "decls/data/engine/audio.h"
// data: gThing = DAT_004e7620

class Thing {
  public:
    Thing();
    ~Thing();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_00360f60() {
    (*(Thing*)((char*)&DAT_004e75b8 + 104)).Thing::Thing();
    atexit(cleanup);
}