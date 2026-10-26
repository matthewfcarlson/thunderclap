// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_363ff0 {
    void f();
};
void wrapper() {
    (*(Obj_363ff0*)((char*)&DAT_004e215c + 16)).f();
}