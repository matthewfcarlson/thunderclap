// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_364040 {
    void f();
};
void wrapper() {
    (*(Obj_364040*)&DAT_004e22fc).f();
}