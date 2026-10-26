// Same code shape as 0x000fc130 (propagated; names are from that function)
#include "decls/data/game/global.h"
// data: gObject_fc260 = DAT_004e0a60

struct Obj_fc260 {
    int f(unsigned int);
};
extern "C" int __cdecl FUN_000fc260(unsigned int param_1) {
    return (*(Obj_fc260**)&DAT_004e0a60)->f(param_1);
}
