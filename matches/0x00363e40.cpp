// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363e40 {
    void f();
};
void wrapper() {
    (*(Obj_363e40*)&DAT_004de608).f();
}