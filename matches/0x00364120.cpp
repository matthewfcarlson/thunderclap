// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Obj_364120 {
    void f();
};
void wrapper() {
    (*(Obj_364120*)((char*)&DAT_004e5a58 + 4)).f();
}