// Same code shape as 0x000fc130 (propagated; names are from that function)
#include "decls/data/engine/audio.h"
// data: gObject_240760 = DAT_004e5ca0
#include "gen/owners.h"

struct Obj_240760 {
};
extern "C" void __cdecl FUN_00240760(unsigned int text) {
    ((owners::Text_240190 *)((*(Obj_240760**)&DAT_004e5ca0)))->FUN_00240190((const owners::Text_240190 *)(hulk_uintptr)(unsigned int)text);
}
