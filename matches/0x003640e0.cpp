// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_3640e0 {
    void f();
};
void wrapper() {
    (*(Obj_3640e0*)&DAT_004e58b8).f();
}