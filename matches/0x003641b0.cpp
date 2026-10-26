// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/engine/om.h"

struct Obj_3641b0 {
    void f();
};
void wrapper() {
    (*(Obj_3641b0*)&DAT_004e5f18).f();
}