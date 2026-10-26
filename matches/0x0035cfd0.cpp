#include "decls/data/game/global.h"

extern "C" int atexit(void (*)(void));
void FUN_00363ca0(void);
class Obj {
  public:
    void Reg(const char*, int);
};
void __stdcall FUN_0035cfd0(void) {
    (*(Obj*)&DAT_004dd738).Reg("sound/rsd", 0);
    atexit((void (*)(void))FUN_00363ca0);
}
