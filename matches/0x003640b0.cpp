// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct Allocator_3640b0 {
    void f();
};
void wrapper() {
    (*(Allocator_3640b0*)&DAT_004e36c8).f();
}