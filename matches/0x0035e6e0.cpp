#include "decls/data/game/global.h"
// data: hulk_at_004e222d = DAT_004e222d

#include "compat/ptr.h"
extern void* g_obj;
extern int atexit(void (*fn)());
extern void F2();
class G {
  public:
    void Reg(const char* name, int arg);
};
void __cdecl FUN_0035e6e0() {
    ((G*)((hulk_intptr)(((char*)&DAT_004e222d) + 0x3)))->Reg("sound/rsd", 0);
    atexit(F2);
}
