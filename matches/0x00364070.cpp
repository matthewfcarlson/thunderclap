// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_364070 {
    void f();
};
void wrapper() {
    (*(Obj_364070*)((char*)&DAT_004e2644 + 4)).f();
}