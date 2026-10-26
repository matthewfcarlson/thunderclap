// Same code shape as 0x00363af0 (propagated; names are from that function)
#include "decls/data/engine/unknown.h"

struct MetaType_3642b0 {
    void f();
};
void wrapper() {
    (*(MetaType_3642b0*)((char*)&DAT_004e635c + 4)).f();
}