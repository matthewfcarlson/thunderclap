#include "decls/data/game/unknown.h"

extern void Reg(const char* name, int a);
extern "C" void FUN_00363b80();
extern "C" int atexit(void (*)());
struct G {
    void Reg(const char* name, int a);
};
void FUN_0035c9d0() {
    (*(G*)&DAT_004dc294).Reg("sound/rsd", 0);
    atexit(FUN_00363b80);
}