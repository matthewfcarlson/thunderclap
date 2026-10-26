// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/unknown.h"

struct Obj_363c60 {
    void f();
};
void wrapper() {
    (*(Obj_363c60*)&DAT_004dd260).f();
}