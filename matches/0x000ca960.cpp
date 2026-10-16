#include "gen/global.h"

class Overlay_ca960 {
    char pad[0x50];
};

void HUDOverlay::vfunc_2() {
    *((char*)this + 0x50) = 0;
}
