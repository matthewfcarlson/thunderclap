#include "decls/data/game/global.h"
// data: gObject_fc130 = DAT_004e0a60

struct Obj_fc130 {
    void f(unsigned int);
};
extern "C" void __cdecl FUN_000fc130(unsigned int param_1) {
    (*(Obj_fc130**)&DAT_004e0a60)->f(param_1);
}
