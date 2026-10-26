// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363e50 {
    void f();
};
void wrapper() {
    (*(Obj_363e50*)&DAT_004de738).f();
}