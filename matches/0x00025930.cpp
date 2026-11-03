#include "gen/owners.h"
unsigned int* owners::Palette_25930::FUN_00025930(unsigned int* out, int index) {
    if (index >= 0 && index < 4)
        *out = colors[index];
    else
        *out = 0xffff00ff;
    return out;
}