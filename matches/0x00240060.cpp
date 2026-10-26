#include "decls/data/engine/audio.h"
// data: sentinel = DAT_004cc02c

extern "C" void freebuf(void*);
struct Str {
    char* data;
    short type;
    void release();
};
void Str::release() {
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