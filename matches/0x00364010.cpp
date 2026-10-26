// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/game/global.h"

struct CStaticAllocator_364010 {
    void f();
};
void wrapper() {
    (*(CStaticAllocator_364010*)&DAT_004e2210).f();
}