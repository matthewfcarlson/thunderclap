// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_3640c0 {
    void f();
};
void wrapper() {
    (*(Obj_3640c0*)&DAT_004e36f0).f();
}