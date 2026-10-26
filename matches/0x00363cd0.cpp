// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363cd0 {
    void f();
};
void wrapper() {
    (*(Obj_363cd0*)&DAT_004dd818).f();
}