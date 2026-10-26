#include "decls/data/engine/audio.h"
// data: gThing = DAT_004e6750

class Thing {
  public:
    void Init();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void FUN_0035fd90() {
    (*(Thing*)((char*)&DAT_004e6748 + 8)).Init();
    atexit(cleanup);
}