// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/hulkfight.h"

struct Obj_363fd0 {
    void f();
};
void wrapper() {
    (*(Obj_363fd0*)((char*)&DAT_004e17c0 + 56)).f();
}