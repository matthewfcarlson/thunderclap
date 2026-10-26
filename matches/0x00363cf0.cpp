// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/hulkfight.h"

struct Obj_363cf0 {
    void f();
};
void wrapper() {
    (*(Obj_363cf0*)&DAT_004dd9d0).f();
}