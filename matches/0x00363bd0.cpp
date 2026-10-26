// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363bd0 {
    void f();
};
void wrapper() {
    (*(Obj_363bd0*)&DAT_004dc330).f();
}