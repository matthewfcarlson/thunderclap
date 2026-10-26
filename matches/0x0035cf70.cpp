#include "decls/data/game/hulkfight.h"
// data: g_thing = DAT_004dd2d0

extern "C" void _atexit(void (*)(void));
class Thing {
  public:
    void Init(const char* name, int flag);
};
void __cdecl FUN_00363c70(void);
void __cdecl FUN_0035cf70(void) {
    (*(Thing*)&DAT_004dd2d0).Init("sound/rsd", 0);
    _atexit(FUN_00363c70);
}
