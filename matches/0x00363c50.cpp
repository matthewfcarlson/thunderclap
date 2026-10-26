// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363c50 {
    void f();
};
void wrapper() {
    (*(Obj_363c50*)&DAT_004dd080).f();
}