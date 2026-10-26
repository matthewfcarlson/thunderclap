// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/engine/audio.h"

struct Obj_364490 {
    void f();
};
void wrapper() {
    (*(Obj_364490*)((char*)&DAT_004e6d28 + 8)).f();
}