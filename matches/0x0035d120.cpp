#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00363cd0();
extern "C" int __cdecl atexit(void (*f)());
struct Reg {
    void Init(char*, int);
};
void InitSound() {
    (*(Reg*)&DAT_004dd818).Init(((char*)&DAT_003f3ea0), 0);
    atexit(FUN_00363cd0);
}
