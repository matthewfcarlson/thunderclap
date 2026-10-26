// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363c40 {
    void f();
};
void wrapper() {
    (*(Obj_363c40*)&DAT_004dd068).f();
}