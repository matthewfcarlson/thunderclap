// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363e30 {
    void f();
};
void wrapper() {
    (*(Obj_363e30*)&DAT_004ddf9c).f();
}