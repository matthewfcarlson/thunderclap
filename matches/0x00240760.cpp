// Same code shape as 0x000fc130 (propagated; names are from that function)
#include "decls/data/engine/audio.h"
// data: gObject_240760 = DAT_004e5ca0

struct Obj_240760 {
    void f(unsigned int);
};
extern "C" void __cdecl FUN_00240760(unsigned int param_1) {
    (*(Obj_240760**)&DAT_004e5ca0)->f(param_1);
}
