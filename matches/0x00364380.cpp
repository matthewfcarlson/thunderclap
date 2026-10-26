// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/engine/audio.h"

struct Obj_364380 {
    void f();
};
void wrapper() {
    (*(Obj_364380*)((char*)&DAT_004e6748 + 8)).f();
}