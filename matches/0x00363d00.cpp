// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363d00 {
    void f();
};
void wrapper() {
    (*(Obj_363d00*)&DAT_004dda08).f();
}