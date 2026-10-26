// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/hulkfight.h"

struct Obj_363c70 {
    void f();
};
void wrapper() {
    (*(Obj_363c70*)&DAT_004dd2d0).f();
}