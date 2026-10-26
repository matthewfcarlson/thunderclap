#include "decls/data/engine/audio.h"
// data: hulk_at_004e68f8 = DAT_004e68f8

#include "compat/ptr.h"
extern "C" int __stdcall FUN_0024fd10(void*);
extern "C" int atexit(void (*)(void));
class Holder_35ff90 {
  public:
    int Run();
};
extern "C" void __cdecl FUN_003643c0();
extern "C" void __cdecl FUN_0035ff90() {
    ((Holder_35ff90*)((hulk_intptr)((char*)&DAT_004e68f8)))->Run();
    atexit(FUN_003643c0);
}
