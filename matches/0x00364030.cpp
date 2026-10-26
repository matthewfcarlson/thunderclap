// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_364030 {
    void f();
};
void wrapper() {
    (*(Obj_364030*)((char*)&DAT_004e226c + 4)).f();
}