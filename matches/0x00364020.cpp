// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_364020 {
    void f();
};
void wrapper() {
    (*(Obj_364020*)((char*)&DAT_004e222d + 3)).f();
}