#include "compat/ptr.h"
extern "C" char hulk_at_004dde6c[];
extern "C" void __cdecl FUN_00363e10();
extern "C" int atexit(void (*)(void));
extern char g_s3f3ea0[];
class Obj {
  public:
    void F(const char* s, int a);
};
void FUN_0035d4c0() {
    ((Obj*)((hulk_intptr)hulk_at_004dde6c))->F(g_s3f3ea0, 0);
    atexit((void (*)(void))((hulk_intptr)((hulk_intptr)(void (__cdecl*)())&FUN_00363e10)));
}
