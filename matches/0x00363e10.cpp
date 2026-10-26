// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/unknown.h"

struct Obj_363e10 {
    void f();
};
void wrapper() {
    (*(Obj_363e10*)&DAT_004dde6c).f();
}