// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/unknown.h"

struct Obj_363b80 {
    void f();
};
void wrapper() {
    (*(Obj_363b80*)&DAT_004dc294).f();
}