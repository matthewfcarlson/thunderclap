// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363e00 {
    void f();
};
void wrapper() {
    (*(Obj_363e00*)&DAT_004dde38).f();
}