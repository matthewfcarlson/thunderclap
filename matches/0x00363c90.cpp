// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363c90 {
    void f();
};
void wrapper() {
    (*(Obj_363c90*)&DAT_004dd704).f();
}