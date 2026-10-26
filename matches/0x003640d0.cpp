// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/unknown.h"

struct Obj_3640d0 {
    void f();
};
void wrapper() {
    (*(Obj_3640d0*)((char*)&DAT_004e3748 + 4)).f();
}