#include "decls/data/game/global.h"
// data: receiver = DAT_004e3690

#include "compat/ptr.h"
#include "gen/global.h"

extern int __cdecl FUN_0024b030(int);
extern int __cdecl FUN_0024c590(int, int);
extern int __cdecl FUN_0026fd50(hulk_intptr, int);
struct Receiver_1f2e00 {
    void run(int);
};
extern void __cdecl FUN_0024bf90(int);
int g800 = 0x800;

void CSoundStreamAllocator::vfunc_1(int a, int c) {
    int x = FUN_0024b030(c);
    x = FUN_0024c590(x, 3000);
    x = FUN_0026fd50(x, g800);
    (*(Receiver_1f2e00**)&DAT_004e3690)->run(x);
    FUN_0024bf90(c);
}
