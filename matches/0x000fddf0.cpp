#include "gen/owners.h"
void owners::C_fddf0::FUN_000fddf0(void* a, unsigned* b) {
    *(void**)(pad + 0x74) = a;
    if (!a) {
        *(unsigned*)(pad + 0x78) = b[0];
        *(unsigned*)(pad + 0x7c) = b[1];
        *(unsigned*)(pad + 0x80) = b[2];
    }
}