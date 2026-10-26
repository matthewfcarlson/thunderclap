// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363ca0 {
    void f();
};
void wrapper() {
    (*(Obj_363ca0*)&DAT_004dd738).f();
}