// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/hulkfight/ai.h"

struct Obj_363f20 {
    void f();
};
void wrapper() {
    (*(Obj_363f20*)((char*)&DAT_004e0d50 + 8)).f();
}