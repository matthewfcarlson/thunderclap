#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
// data: g_sound = DAT_004e0f60, g_sound_rsd = DAT_003f3ea0

extern "C" void __cdecl FUN_00363f40();
extern char* g_bss;
extern void __cdecl _atexit(void (*)());
class Sound {
  public:
    void Init(const char* b, int a);
};
void FUN_0035e380() {
    (*(Sound*)&DAT_004e0f60).Init(((char*)&DAT_003f3ea0), 0);
    _atexit(FUN_00363f40);
}
