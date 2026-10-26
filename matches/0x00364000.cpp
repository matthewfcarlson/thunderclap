// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_364000 {
    void f();
};
void wrapper() {
    (*(Obj_364000*)&DAT_004e21f8).f();
}