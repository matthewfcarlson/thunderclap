// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/unknown.h"

struct Obj_363b30 {
    void f();
};
void wrapper() {
    (*(Obj_363b30*)&DAT_004dc118).f();
}