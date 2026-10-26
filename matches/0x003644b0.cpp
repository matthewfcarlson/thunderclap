// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/engine/audio.h"

struct Obj_3644b0 {
    void f();
};
void wrapper() {
    (*(Obj_3644b0*)((char*)&DAT_004e6de0 + 72)).f();
}