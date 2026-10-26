// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/hulkfight/scenario.h"

struct Obj_363fb0 {
    void f();
};
void wrapper() {
    (*(Obj_363fb0*)&DAT_004e1768).f();
}