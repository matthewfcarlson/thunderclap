#include "decls/data/engine/audio.h"
// data: sentinel = DAT_004cc02c
#include "gen/owners.h"

extern "C" void freebuf(void*);
void owners::Str_240060::FUN_00240060() {
    if (type == 2) {
        char* p = data;
        if (*(volatile short*)(p - 4) == 1) {
            if (p != (*(char**)&DAT_004cc02c)) {
                freebuf(p - 8);
                return;
            }
        } else {
            --*(short*)(p - 4);
        }
    }
}